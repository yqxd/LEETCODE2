#include <math.h>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// Given a binary tree, determine if it is height-balanced.

// For this problem, a height-balanced binary tree is defined as:

// a binary tree in which the left and right subtrees of every node differ in
// height by no more than 1.

// Example 1:

// Given the following tree [3,9,20,null,null,15,7]:

//     3
//    / \
//   9  20
//     /  \
//    15   7
// Return true.

// Example 2:

// Given the following tree [1,2,2,3,3,null,null,4,4]:

//        1
//       / \
//      2   2
//     / \
//    3   3
//   / \
//  4   4
// Return false.

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
    bool isBalanced(TreeNode* root) {
        set(root);
        return check(root);
    }
    int set(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        } else {
            root->val = max(set(root->left), set(root->right)) + 1;
            return root->val;
        }
    }
    bool check(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        if ((root->left == nullptr && root->right != nullptr &&
             root->right->val > 1) ||
            (root->right == nullptr && root->left != nullptr &&
             root->left->val > 1)) {
            return false;
        }
        if (root->left != nullptr && root->right != nullptr &&
            abs(root->left->val - root->right->val) > 1) {
            return false;
        }
        return check(root->left) && check(root->right);
    }
};

int main() {
    struct TreeNode a1, a2, a3, a4, a5, a6, a7, *b1 = &a1, *b2 = &a2, *b3 = &a3,
                                                *b4 = &a4, *b5 = &a5, *b6 = &a6,
                                                *b7 = &a7;
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
    b4->left = b6;
    b4->right = b7;
    cout << Solution().isBalanced(b1) << endl;
    system("Pause");
}