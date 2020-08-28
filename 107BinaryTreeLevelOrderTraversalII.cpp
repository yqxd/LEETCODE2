// Given a binary tree, return the bottom-up level order traversal of its nodes'
// values. (ie, from left to right, level by level from leaf to root).

// For example:
// Given binary tree [3,9,20,null,null,15,7],
//     3
//    / \
//   9  20
//     /  \
//    15   7
// return its bottom-up level order traversal as:
// [
//   [15,7],
//   [9,20],
//   [3]
// ]

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right) {}
};

class Solution {
   public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {}
};

int main() {
    vector<int> a = {3, 9, 20, 15, 7};
    vector<int> b = {9, 3, 15, 20, 7};
    Solution A;
    struct TreeNode* B = A.buildTree(a, b);
    cout << B->val << endl;
    cout << B->left->val << endl;
    cout << B->right->val << endl;
    cout << B->right->right->val << endl;
    cout << B->right->left->val << endl;
    system("pause");
}
