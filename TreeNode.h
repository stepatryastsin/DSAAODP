#ifndef TREE_NODE_H
#define TREE_NODE_H
//=======================//
struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};
struct TreeNode* createtree(int val);
void freememtree(struct TreeNode* root);
struct TreeNode* insert(struct TreeNode* root, int val);
struct TreeNode* createnode(int val);

//=======================//
#endif // !TREE_NODE_H