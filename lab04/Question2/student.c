#include <stdbool.h>
#include <stddef.h>

/*
Question 2: Symmetric Tree

Given the root of a binary tree, check whether it is symmetric
around its center.

A tree is symmetric if the left subtree is a mirror reflection
of the right subtree.

Examples:

Example 1:
Input:
        1
       / \
      2   2
     / \ / \
    3  4 4  3
Output: true

Example 2:
Input:
        1
       / \
      2   2
       \   \
       3    3
Output: false

Function to complete:
    bool isSymmetric(struct TreeNode* root);

Note:
- An empty tree is considered symmetric.
- You should compare the left subtree and right subtree
  as mirror images.
*/

/*
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};



bool isSymmetric(struct TreeNode* root) {
    if (root == NULL) return true;
    struct TreeNode* stack1[1000];
    struct TreeNode* stack2[1000];
    int top1 = -1, top2 = -1;
    stack1[++top1] = root->left;
    stack2[++top2] = root->right;
    while (top1 >= 0 && top2 >= 0) {
        struct TreeNode* left = stack1[top1--];
        struct TreeNode* right = stack2[top2--];
        if (left == NULL && right == NULL) continue;
        if (left == NULL || right == NULL) return false;
        if (left->val != right->val) return false;
        stack1[++top1] = left->left;
        stack1[++top1] = left->right;
        stack2[++top2] = right->right;
        stack2[++top2] = right->left;
    }
    return true;
}