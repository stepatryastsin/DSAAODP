#include "235. Lowest Common Ancestor of a Binary Search Tree.h"
#include"TreeNode.h"
#include "Stack.h"
#include<stdio.h>
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if (!root || !p || !q) { 
        printf("Invalid input.\n");
        return NULL;
    }

    struct Stack* stk = allocatemem(); 
    push(stk, root); 

    while (!empty(stk)) { 
        struct TreeNode* current = pop(stk); 

        if (current->val >= p->val && current->val <= q->val) { 
            return current;
        }
        else if (current->left && (p->val <= current->val || q->val >= current->val)) { // Проверяем, находится ли текущий узел между значениями p и q
            push(stk, current); 
        }

        else if (current->right && (p->val >= current->val || q->val <= current->val)) {
            if (p->val == current->val || q->val == current->val) {
                return current;
            }
            push(stk, current->right);
        }
    }

    freemem(stk); 
    return NULL; 
}