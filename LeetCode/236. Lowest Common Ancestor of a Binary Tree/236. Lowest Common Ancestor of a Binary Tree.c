#include "236. Lowest Common Ancestor of a Binary Tree.h"
#include<stdio.h>
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if (root == NULL || root == p || root == q) {
        return root;
    }
    struct TreeNode* right = lowestCommonAncestor(root->right, p, q);
    struct TreeNode* left = lowestCommonAncestor(root->left, p, q);

    if (right != NULL || left != NULL) {
        return root;
    }

    return NULL;
    
}