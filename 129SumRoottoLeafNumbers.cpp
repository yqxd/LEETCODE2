#include <math.h>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// Given a binary tree containing digits from 0-9 only, each root-to-leaf path
// could represent a number.

// An example is the root-to-leaf path 1->2->3 which represents the number 123.

// Find the total sum of all root-to-leaf numbers.

// Note: A leaf is a node with no children.

// Example:

// Input: [1,2,3]
//     1
//    / \
//   2   3
// Output: 25
// Explanation:
// The root-to-leaf path 1->2 represents the number 12.
// The root-to-leaf path 1->3 represents the number 13.
// Therefore, sum = 12 + 13 = 25.
// Example 2:

// Input: [4,9,0,5,1]
//     4
//    / \
//   9   0
//  / \
// 5   1
// Output: 1026
// Explanation:
// The root-to-leaf path 4->9->5 represents the number 495.
// The root-to-leaf path 4->9->1 represents the number 491.
// The root-to-leaf path 4->0 represents the number 40.
// Therefore, sum = 495 + 491 + 40 = 1026.

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
    int sumNumbers(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        return s(root, 0);
    }
    int s(TreeNode* root, int i) {
        int result = 0;
        if (root->left == nullptr && root->right == nullptr) {
            return i * 10 + root->val;
        }
        if (root->left != nullptr) {
            result += s(root->left, 10 * i + root->val);
        }
        if (root->right != nullptr) {
            result += s(root->right, 10 * i + root->val);
        }
        return result;
    }
};