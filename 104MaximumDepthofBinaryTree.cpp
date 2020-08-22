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
    int maxDepth(TreeNode* root) { return nowDepth(root, 0); }
    int nowDepth(TreeNode* root, int k) {
        if (root == NULL) {
            return k;
        } else {
            return max(nowDepth(root->left, k + 1),
                       nowDepth(root->right, k + 1));
        }
    }
    int max(int a, int b) {
        if (a > b) {
            return a;
        } else {
            return b;
        }
    }
};