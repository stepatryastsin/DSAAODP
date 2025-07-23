#include "1123. Lowest Common Ancestor of Deepest Leaves.h"
#include<stdio.h>
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};
struct TreeNode* helper(struct TreeNode* root, int* d) {
    if (root == NULL) {
        *d = 0;
        return NULL;
    }
    int dleft = 0;
    int dright = 0;
    struct TreeNode* left = helper(root->left, &dleft);
    struct TreeNode* right = helper(root->right, &dright);
    *d = (dleft > dright ? dleft : dright) + 1;
    if (dleft == dright) {
        return root;
    }

    return (dleft > dright) ? left : right;

}
struct TreeNode* lcaDeepestLeaves(struct TreeNode* root) {
    if (root == NULL) {
        return NULL;
    }
    int d = 0;
    return helper(root, &d);
}