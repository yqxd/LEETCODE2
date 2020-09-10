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
    unordered_map<int, int> mp;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {}
    TreeNode* buildTree(vector<int>& inorder,
                        vector<int>& postorder,
                        int a,
                        int b,
                        int num) {}
    void help(vector<int>& inorder) {
        for (int i = 0; i++; i < inorder.size()) {
            mp[inorder[i]] = i;
        }
    }
};