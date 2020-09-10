#include <math.h>
#include <stdio.h>
#include <algorithm>
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

// Given an array where elements are sorted in ascending order, convert it to a
// height balanced BST.

// For this problem, a height-balanced binary tree is defined as a binary tree
// in which the depth of the two subtrees of every node never differ by more
// than 1.

// Example:

// Given the sorted array: [-10,-3,0,5,9],

// One possible answer is: [0,-3,9,-10,null,5], which represents the following
// height balanced BST:

//       0
//      / \
//    -3   9
//    /   /
//  -10  5

class Solution {
   public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.size() == 0) {
            return nullptr;
        }
        int n = nums.size() / 2;
        TreeNode* A = new TreeNode(nums[n]);
        vector<int> num1, num2;
        num1.assign(nums.begin(), nums.begin() + n);
        num2.assign(nums.begin() + n + 1, nums.end());
        A->left = sortedArrayToBST(num1);
        A->right = sortedArrayToBST(num2);
        return A;
    }
};

int main() {
    vector<int> A = {1, 2, 3, 4, 5, 6};
    Solution C;
    TreeNode* B = C.sortedArrayToBST(A);
    system("Pause");
}