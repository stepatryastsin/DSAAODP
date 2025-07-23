#include"1026. Maximum Difference Between Node and Ancestor.h"
#include<stdio.h>
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};
int funhelp(struct TreeNode* root, int max, int min) {
    if (root == NULL) {
        return max - min;
    }
    min = (root->val < min) ? root->val : min;
    max = (root->val > max) ? root->val : max;
    int left = funhelp(root->left, max, min);
    int right = funhelp(root->right, max, min);
    return (left > right) ? left : right;
}
int maxAncestorDiff(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    return funhelp(root, root->val, root->val);
}