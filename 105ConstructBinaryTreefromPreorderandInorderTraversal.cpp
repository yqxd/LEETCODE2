#include <stdio.h>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// Given preorder and inorder traversal of a tree, construct the binary tree.

// Note:
// You may assume that duplicates do not exist in the tree.

// For example, given

// preorder = [3,9,20,15,7]
// inorder = [9,3,15,20,7]
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
    int num1 = 1, *num = &num1;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        *num = 1;
        if (inorder.size() == 0) {
            return nullptr;
        } else {
            struct TreeNode root1 = TreeNode(preorder[0]), *root = &root1;
            int loc = find(preorder[0], inorder, 0, preorder.size() - 1);
            root->left = build(preorder, inorder, 0, loc - 1);
            root->right =
                build(preorder, inorder, loc + 1, preorder.size() - 1);
            return root;
        }
    }
    TreeNode* build(vector<int> preorder, vector<int> inorder, int a, int b) {
        if (a == b + 1)
            return nullptr;
        struct TreeNode root1 = TreeNode(preorder[*num]), *root = &root1;
        int loc = find(preorder[*num], inorder, a, b);
        (*num)++;
        root->left = build(preorder, inorder, a, loc - 1);
        root->right = build(preorder, inorder, loc + 1, b);
        return root;
    }
    int find(int num, vector<int> inorder, int a, int b) {
        for (int i = a; i <= b; i++) {
            if (inorder[i] == num)
                return i;
        }
        return -1;
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (root == NULL)
            return ans;
        TreeNode* curr = root;
        bool done = false;
        stack<TreeNode*> st;
        while (!done) {
            if (curr != NULL) {
                st.push(curr);
                curr = curr->left;
            } else if (st.empty())
                done = true;
            else {
                curr = st.top();
                st.pop();
                ans.push_back(curr->val);
                curr = curr->right;
            }
        }
        return ans;
    }
};

int main() {
    vector<int> a = {3, 9, 20, 15, 7};
    vector<int> b = {9, 3, 15, 20, 7};
    Solution A;
    struct TreeNode* B = A.buildTree(a, b);
    cout << B->val << endl;
    cout << B->left->val << endl;
    cout << B->right->val << endl;
    cout << B->right->right->val << endl;
    cout << B->right->left->val << endl;
    system("pause");
}
