#include <stdio.h>
#include"TreeNode.h"
#include"235. Lowest Common Ancestor of a Binary Search Tree.h"

int main()
{
    struct TreeNode* tree = createtree(2);
    tree = insert(tree, 1);
    struct TreeNode* p = createtree(2);
    struct TreeNode* q = createtree(1);
    struct TreeNode* f = lowestCommonAncestor(tree, p, q);
    return 0;
}
