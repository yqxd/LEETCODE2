// Given a binary tree, imagine yourself standing on the right side of it,
// return the values of the nodes you can see ordered from top to bottom.

// Example:

// Input: [1,2,3,null,5,null,4]
// Output: [1, 3, 4]
// Explanation:

//    1            <---
//  /   \
// 2     3         <---
//  \     \
//   5     4       <---

#include <cmath>
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right)
            : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> rightSideView(TreeNode *root) {
        vector<int> result = {};
        vector<TreeNode *> R = {};
        if (root) {
            R.push_back(root);
        }
        int i;
        while (!R.empty()) {
            result.push_back(R[R.size() - 1]->val);
            i = 0;
            while (i < R.size()) {
                root = R[i];
                R.erase(R.begin() + i);
                if (root->left) {
                    R.insert(R.begin() + i++, root->left);
                }
                if (root->right) {
                    R.insert(R.begin() + i++, root->right);
                }
            }
        }
        return result;
    }
};

int main() {
    Solution A;
    TreeNode Q = TreeNode(1), W = TreeNode(2), E = TreeNode(3), R = TreeNode(4), T = TreeNode(5);
    TreeNode *q = &Q, *w = &W, *e = &E, *r = &R, *t = &T;
    Q.val = 1;
    W.val = 2;
    E.val = 3;
    R.val = 4;
    T.val = 5;
    Q.left = &W;
    W.right = &E;
    Q.right = &R;
    R.right = &T;
    A.rightSideView(q);
}