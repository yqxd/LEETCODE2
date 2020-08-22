/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#include <stdio.h>
bool isS(struct TreeNode* left, struct TreeNode* right) {
    if (left == NULL || right == NULL) {
        if (left == NULL && right == NULL) {
            return true;
        } else {
            return false;
        }
    } else {
        if (left->val == right->val) {
            return isS(left->left, right->right) &&
                   isS(left->right, right->left);
        } else {
            return false;
        }
    }
}

bool isSymmetric(struct TreeNode* root) {
    if (root == NULL) {
        return true;
    }
    return isS(root->left, root->right);
}