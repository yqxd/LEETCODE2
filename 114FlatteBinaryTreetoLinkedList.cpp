// Given a binary tree, flatten it to a linked list in-place.

// For example, given the following tree:

//     1
//    / \
//   2   5
//  / \   \
// 3   4   6
// The flattened tree should look like:

// 1
//  \
//   2
//    \
//     3
//      \
//       4
//        \
//         5
//          \
//           6

#include <math.h>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <unordered_map>
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
    vector<TreeNode*> result;
    void flatten(TreeNode* root) {
        result = {};
        if (root == nullptr) {
            return;
        } else {
            fl(root);
        }
        for (int i = 0; i < result.size() - 1; i++) {
            result[i]->right = result[i + 1];
            result[i]->left = nullptr;
        }
    }
    void fl(TreeNode* root) {
        result.push_back(root);
        if (root->left != nullptr) {
            fl(root->left);
        }
        if (root->right != nullptr) {
            fl(root->right);
        }
    }
};

int main() {
    struct TreeNode a1, a2, a3, a4, a5, a6, *b1 = &a1, *b2 = &a2, *b3 = &a3,
                                            *b4 = &a4, *b5 = &a5, *b6 = &a6;
    int* k = nullptr;
    cout << (k == nullptr) << endl;
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
    A.flatten(b1);
    while (b1->right != nullptr) {
        cout << b1->val << endl;
        b1 = b1->right;
    }
}