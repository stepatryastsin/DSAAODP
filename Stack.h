#ifndef STACK
#define STACK
#define INIT_STACK 10;
#define MULT 2
struct Stack;

//==========================//

struct Stack* allocatemem();
void freemem(struct Stack** stk);

//==========================//

void push(struct Stack* stk,struct TreeNode* val);
struct TreeNode* pop(struct Stack* stk);
struct TreeNode* peek(struct Stack* stk);
int empty(struct Stack* stk);
void resize(struct Stack* stk);

//===========================//


#endif // !STACK_H
