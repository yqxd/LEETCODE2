// Given a binary tree, return the level order traversal of its nodes' values.
// (ie, from left to right, level by level).

// For example:
// Given binary tree [3,9,20,null,null,15,7],
//     3
//    / \
//   9  20
//     /  \
//    15   7
// return its level order traversal as:
// [
//   [3],
//   [9,20],
//   [15,7]
// ]

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

#define False 0
#define True 1

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) {
            return vector<vector<int>>();
        }
        vector<vector<int>> result = {{}};
        vector<struct TreeNode*> stack = {root};
        struct TreeNode* now;
        int n = 1;
        while (1) {
            now = stack[stack.size() - 1];
            result[result.size() - 1].insert(result[result.size() - 1].end(),
                                             now->val);
            stack.pop_back();
            if (now->left != nullptr) {
                stack.insert(stack.begin(), now->left);
            }
            if (now->right != nullptr) {
                stack.insert(stack.begin(), now->right);
            }
            n--;
            if (n == 0) {
                n = stack.size();
                if (n == 0) {
                    break;
                }
                result.push_back({});
            }
        }
        return result;
    }
};

int main() {
    struct TreeNode a1, a2, a3, a4, a5, a6, *b1 = &a1, *b2 = &a2, *b3 = &a3,
                                            *b4 = &a4, *b5 = &a5, *b6 = &a6;
    a1.val = 1;
    a2.val = 2;
    a3.val = 3;
    a4.val = 4;
    a5.val = 5;
    a6.val = 6;
    b1->left = b2;
    b1->right = b3;
    b2->left = b4;
    b2->right = b5;
    b5->left = b6;
    Solution A;
    vector<vector<int>> B = A.levelOrder(b1);
    for (auto i : B) {
        for (auto j : i) {
            cout << j << endl;
        }
    }
}
