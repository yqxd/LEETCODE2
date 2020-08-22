/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
   public:
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) {
            return true;
        } else {
            return (Symmetricone(root->left, root->right));
        }
    }
    bool Symmetricone(TreeNode* left, TreeNode* right) {
        if (left == NULL || right == NULL) {
            if (left == NULL && right == NULL) {
                return true;
            } else {
                return false;
            }
        } else {
            if (left->val == right->val) {
                return Symmetricone(left->left, right->right) &&
                       Symmetricone(left->right, right->left);
            } else {
                return false;
            }
        }
    }
};