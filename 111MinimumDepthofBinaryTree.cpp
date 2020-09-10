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
    int minDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        } else {
            return Depth(root);
        }
    }
    int Depth(TreeNode* root) {
        if (root->left == nullptr) {
            if (root->right == nullptr) {
                return 1;
            } else {
                return Depth(root->right)
            }
        } else {
            if (root->right == nullptr) {
                return Depth(root->left);
            } else {
                return min(Depth(root->left), Depth(root->right)) + 1;
            }
        }
    }
};