#include <math.h>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
using namespace std;

// Given inorder and postorder traversal of a tree, construct the binary tree.

// Note:
// You may assume that duplicates do not exist in the tree.

// For example, given

// inorder = [9,3,15,20,7]
// postorder = [9,15,7,20,3]
// Return the following binary tree:

//     3
//    / \
//   9  20
//     /  \
//    15   7

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
    map<int, int> ma;
    int k1, *k = &k1;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        *k = postorder.size() - 1;
        if (*k == -1) {
            return nullptr;
        }
        for (int i = 0; i < inorder.size(); i++) {
            ma[inorder[i]] = i;
        }
        return buildone(inorder, postorder, 0, inorder.size() - 1, k);
    }
    TreeNode* buildone(vector<int>& inorder,
                       vector<int>& postorder,
                       int a,
                       int b,
                       int* k) {
        int position = ma[postorder[*k]];
        if (*k == -1) {
            return nullptr;
        }
        *k = *k - 1;
        struct TreeNode* root = new TreeNode(inorder[position]);
        if (position < b) {
            root->right = buildone(inorder, postorder, position + 1, b, k);
        }
        if (position > a) {
            root->left = buildone(inorder, postorder, a, position - 1, k);
        }
        return root;
    }
};

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

int main() {
    vector<int> a = {}, b = {};
    Solution A;
    TreeNode* t = A.buildTree(a, b);
    cout << t->val << endl;
    cout << t->left->val << endl;
    cout << t->right->val << endl;
    cout << t->right->left->val << endl;
    cout << t->right->right->val << endl;
    system("Pause");
}