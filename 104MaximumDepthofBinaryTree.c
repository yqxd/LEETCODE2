/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int max(int a, int b) {
    if (a >= b) {
        return a;
    } else {
        return b;
    }
}

int maxDepth(struct TreeNode* root) {
    return m(root, 0);
}

int m(struct TreeNode* root, int now) {
    if (root == NULL) {
        return now;
    } else {
        return max(m(root->left, now + 1), m(root->right, now + 1));
    }
}
