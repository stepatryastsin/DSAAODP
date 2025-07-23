#define INIT_STACK 10
#define MULT 2
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

struct Stack {
    int* sym;
    int top;
    int size;
};

struct Stack* allocatemem() {
    struct Stack* stack = malloc(sizeof(struct Stack));
    if (!stack) {
        fprintf(stderr, "Error: Memory for stack was not allocated successfully.\n");
        return NULL;
    }
    stack->size = INIT_STACK;
    stack->sym = malloc(sizeof(int) * stack->size);
    if (!stack->sym) {
        fprintf(stderr, "Error: Memory for data of stack was not allocated successfully.\n");
        free(stack);
        return NULL;
    }
    stack->top = 0;
    return stack;
}

void freemem(struct Stack** stk) {
    free((*stk)->sym);
    free(*stk);
    *stk = NULL;
}

void push(struct Stack* stk, int sym) {
    if (stk->top >= stk->size) {
        stk->size *= MULT;
        stk->sym = realloc(stk->sym, stk->size * sizeof(int));
        if (!stk->sym) {
            fprintf(stderr, "Error: Memory for data of stack was not reallocated successfully.\n");
            exit(1);
        }
    }
    stk->sym[stk->top++] = sym;
}

int pop(struct Stack* stk) {
    if (stk->top == 0) {
        fprintf(stderr, "Error: The stack is empty.\n");
        return -1; // Вернем -1 в случае ошибки
    }
    return stk->sym[--stk->top];
}

int peek(struct Stack* stk) {
    if (stk->top <= 0) {
        fprintf(stderr, "Error: The stack is empty.\n");
        return -1; // Вернем -1 в случае ошибки
    }
    return stk->sym[stk->top - 1];
}

int empty(struct Stack* stk) {
    return stk->top == 0;
}
int scoreOfParentheses(char* s) {
    struct Stack* stack = allocatemem();
    push(stack, 0); // Инициализируем стек с 0 для хранения результата

    while (*s != '\0') {
        if (*s == '(') {
            push(stack, 0);
        }
        else {
            int top = pop(stack);
            int secondTop = pop(stack);
            int score = secondTop + MAX(2 * top, 1);
            push(stack, score);
        }
        s++; // Увеличиваем указатель на следующий символ
    }

    int result = pop(stack);
    //freemem(stack);
    return result;
}