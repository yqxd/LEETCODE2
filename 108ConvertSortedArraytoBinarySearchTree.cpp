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
    TreeNode* sortedArrayToBST(vector<int>& nums) {}
};