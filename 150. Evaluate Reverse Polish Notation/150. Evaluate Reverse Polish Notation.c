#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define STARTSIZE 10

struct Stack {
    int* res;    // Array to hold the stack elements
    int size;    // Current allocated size
    int cap;     // Current number of elements in the stack
};

// Function to initialize a stack
struct Stack* allmem() {
    struct Stack* mem = malloc(sizeof(struct Stack));
    if (mem == NULL) {
        printf("ERROR: Memory allocation failed for stack.\n");
        exit(1);
    }
    mem->size = STARTSIZE;
    mem->cap = 0;
    mem->res = malloc(sizeof(int) * mem->size);
    if (mem->res == NULL) {
        printf("ERROR: Memory allocation failed for stack elements.\n");
        free(mem);  // Clean up before exiting
        exit(1);
    }
    return mem;
}

// Function to resize the stack
void resize(struct Stack* stk) {
    stk->size *= 2;
    stk->res = realloc(stk->res, sizeof(int) * stk->size);
    if (stk->res == NULL) {
        printf("ERROR: Memory reallocation failed.\n");
        free(stk);  // Clean up before exiting
        exit(1);
    }
}

// Function to push an element onto the stack
void push(struct Stack* stk, int x) {
    if (stk->cap >= stk->size) {
        resize(stk);
    }
    stk->res[stk->cap++] = x;
}

// Function to pop an element from the stack
int pop(struct Stack* stk) {
    if (stk->cap <= 0) {
        printf("ERROR: Stack underflow.\n");
        exit(1);
    }
    return stk->res[--stk->cap];
}

// Function to evaluate a Reverse Polish Notation expression
int evalRPN(char** tokens, int tokensSize) {
    struct Stack* stk = allmem();

    for (int i = 0; i < tokensSize; ++i) {
        if (isdigit(tokens[i][0]) || (tokens[i][0] == '-' && isdigit(tokens[i][1]))) { // Handle negative numbers too
            push(stk, atoi(tokens[i]));  // Convert string to integer and push
        }
        else {
            int f = pop(stk);
            int s = pop(stk);
            switch (tokens[i][0]) {
            case '+':
                push(stk, s + f);
                break;
            case '-':
                push(stk, s - f);
                break;
            case '*':
                push(stk, s * f);
                break;
            case '/':
                if (f == 0) {
                    printf("ERROR: Division by zero.\n");
                    free(stk->res);
                    free(stk);
                    exit(1);
                }
                push(stk, s / f);
                break;
            default:
                printf("ERROR: Unknown operator.\n");
                free(stk->res);
                free(stk);
                exit(1);
            }
        }
    }

    int result = pop(stk);
    free(stk->res);
    free(stk);
    return result;
}
