//
// Created by lenovo on 2021/9/25.
//


#include "algorithm"
#include "iostream"
#include "vector"
#include "map"

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:

    vector<int> result = {};

    vector<int> postorderTraversal(TreeNode *root) {
        if (root != NULL) {
            postorderTraversal(root->left);
            postorderTraversal(root->right);
            result.push_back(root->val);
        }
        return result;
    }
};