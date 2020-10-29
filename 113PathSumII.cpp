// Given a binary tree and a sum, find all root-to-leaf paths where each path's
// sum equals the given sum.

// Note: A leaf is a node with no children.

// Example:

// Given the below binary tree and sum = 22,

//       5
//      / \
//     4   8
//    /   / \
//   11  13  4
//  /  \    / \
// 7    2  5   1
// Return:

// [
//    [5,4,11,2],
//    [5,8,4,5]
// ]

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

class Solution {
public:
    vector<int>path;
    vector<vector<int>>result;
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        helper(root,sum);
        return result;
    }
    
    void helper(TreeNode* root,int sum)
    {
        if (root==NULL)
            return;
        sum-=root->val;
        path.push_back(root->val);
        if(root->left==NULL and root->right==NULL and (sum==0))
            result.push_back(path);
        helper (root->left,sum);
        helper (root->right,sum);
        path.pop_back();
        
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
    for (auto i : A.pathSum(b1, 7)) {
        for (auto j : i) {
            cout << j << endl;
        }
    }
    system("Pause");
}