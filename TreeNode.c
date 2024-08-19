#include "TreeNode.h"
#include <stdlib.h>
#include <stdio.h>
struct TreeNode* createtree(int val)
{
	struct TreeNode* root = malloc(sizeof(struct TreeNode));
	if (!root) {
		fprintf(stderr, " Error : Memory for root was not allocated successfully.\n");
		return NULL;
	}
	root->left = NULL;
	root->right = NULL;
	root->val = val;
	return root;
}

void freememtree(struct TreeNode* root)
{
	if (root == NULL) {
		free(root);
	}
	
	if (root->left != NULL) {
		freememtree(root->left);
	}
	freememtree(root->right);
}

struct TreeNode* insert(struct TreeNode *root, int val)
{
	if (root == NULL) {
		return createnode(val);
    }
	if (root->val > val) {
		root->left = insert(root->left, val);
	}
	else if (root->val < val) {
		root->right = insert(root->right, val);
	}
	return root;
}

struct TreeNode* createnode(int val)
{
	struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	if (!node) {
		fprintf(stderr, " Error : Memory for node was not allocated successfully.\n");
		return NULL;
	}
	node->val = val;
	node->left = NULL;
	node->right = NULL;
	return node;
}
