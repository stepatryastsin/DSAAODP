#include "235. Lowest Common Ancestor of a Binary Search Tree.h"
#include"TreeNode.h"
#include "Stack.h"
#include<stdio.h>
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if (!root || !p || !q) {
        printf("Invalid input.\n");
        return NULL;
    }

    struct TreeNode* current = root;
    while (current) {
        if (p->val < current->val && q->val < current->val) {
            current = current->left;
        }
        else if (p->val > current->val && q->val > current->val) {
            current = current->right;
        }
        else {
            return current;
        }
    }

    return NULL;
}
