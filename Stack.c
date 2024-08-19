#include "Stack.h"
#include "TreeNode.h"
#include <stdlib.h>
#include <stdio.h>
struct Stack {
	struct TreeNode** arr;
	int   top;
	int  size;
};
struct Stack* allocatemem()
{
	struct Stack* stack = malloc(sizeof(struct Stack));
	if (!stack) {
		fprintf(stderr, " Error : Memory for stack was not allocated successfully.\n");
		return NULL;
	}
	stack->size = INIT_STACK;
	stack->arr = malloc(sizeof(struct TreeNode*)* stack->size);
	if (!stack->arr) {
		fprintf(stderr, " Error : Memory for data of stack was not allocated successfully.\n");
		free(stack->arr);
		return NULL;
	}
	stack->top = 0;
	return stack;
}

void freemem(struct Stack** stk)
{
	free((*stk)->arr);
	free(*stk);
	*stk = NULL;
}

void push(struct Stack* stk, struct TreeNode* val)
{
	if (stk->top >= stk->size) {
		resize(stk);
    }
	stk->arr[stk->top] = val;
	stk->top++;
}

struct TreeNode* pop(struct Stack* stk)
{
	if (stk->top == 0) {
		fprintf(stderr, " Error : The stack is empty.\n");
	}
	stk->top--;
	return (stk)->arr[stk->top];
}

struct TreeNode* peek(struct Stack* stk)
{
	if (stk->top <= 0) {
		fprintf(stderr, " Error : The stack is empty.\n");
	}
	return &stk->arr[stk->top-1];
}

int empty(struct Stack* stk)
{
	return stk->top == 0;
}

void resize(struct Stack* stk) {
	stk->size *= MULT;
	stk->arr = realloc(stk->arr, stk->size * sizeof(struct TreeNode*));
	if (!stk->arr) {
		fprintf(stderr, "Error: Memory for data of stack was not reallocated successfully.\n");
		exit(1);
	}
}
