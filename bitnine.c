#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    enum TypeTag {
        EMPTY,
        INTEGER,
        FUNCTION
    } type;
    union {
        int value;
        struct {
            struct Node* left;
            struct Node* right;
        } function;
    } data;
} Node;

Node* makeFunc(enum TypeTag type) {
    Node* func = (Node*)malloc(sizeof(Node));
    func->type = FUNCTION;
    func->data.function.left = NULL;
    func->data.function.right = NULL;
    return func;
}

Node* makeInt(int value) {
    Node* integer = (Node*)malloc(sizeof(Node));
    integer->type = INTEGER;
    integer->data.value = value;
    return integer;
}

int calc(Node* node) {
    if (node->type == INTEGER) {
        return node->data.value;
    } else if (node->type == FUNCTION) {
        Node* left = node->data.function.left;
        Node* right = node->data.function.right;

        if (left == NULL || right == NULL) {
            return 0;
        }

        int leftValue = calc(left);
        int rightValue = calc(right);

        switch (node->data.function.op) {
            case ADD:
                return leftValue + rightValue;
            case SUB:
                return leftValue - rightValue;
            case MUL:
                return leftValue * rightValue;
            // Add more operations as needed
            default:
                return 0;
        }
    }

    return 0;
}

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }

    Node* fib = makeFunc(EMPTY);
    fib->data.function.op = ADD;
    fib->data.function.left = makeInt(0);
    fib->data.function.right = makeInt(1);

    for (int i = 2; i <= n; i++) {
        Node* temp = fib->data.function.right;
        fib->data.function.right = makeFunc(EMPTY);
        fib->data.function.right->data.function.op = ADD;
        fib->data.function.right->data.function.left = temp;
        fib->data.function.right->data.function.right = fib->data.function.left;
        fib->data.function.left = temp;
    }

    int result = calc(fib);
    free(fib);
    return result;
}

int main() {
    Node* add = makeFunc(EMPTY);
    add->data.function.op = ADD;
    add->data.function.left = makeInt(10);
    add->data.function.right = makeInt(6);
    int addResult = calc(add);
    printf("add: %d\n", addResult);

    Node* mul = makeFunc(EMPTY);
    mul->data.function.op = MUL;
    mul->data.function.left = makeInt(5);
    mul->data.function.right = makeInt(4);
    int mulResult = calc(mul);
    printf("mul: %d\n", mulResult);

    Node* sub = makeFunc(EMPTY);
    sub->data.function.op = SUB;
    sub->data.function.left = mul;
    sub->data.function.right = makeInt(1);
    int subResult = calc(sub);
    printf("sub: %d\n", subResult);

    Node* fibo = makeFunc(EMPTY);
    fibo->data.function.op = SUB;
    fibo->data.function.left = sub;
    fibo->data.function.right = makeInt
        
        
       
// Differences between the three approaches:

// Recursive Approach:

// Advantage: Simple and straightforward implementation.
// Disadvantage: It can have exponential time complexity and may lead to redundant computations for larger values of n.
// Top-Down Dynamic Programming Approach:

// Advantage: Memoization eliminates redundant computations, resulting in improved efficiency compared to the recursive approach.
// Disadvantage: It requires additional memory for the memoization array.
