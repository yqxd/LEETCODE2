// You are given a perfect binary tree where all leaves are on the same level,
// and every parent has two children. The binary tree has the following
// definition:

// struct Node {
//   int val;
//   Node *left;
//   Node *right;
//   Node *next;
// }
// Populate each next pointer to point to its next right node. If there is no
// next right node, the next pointer should be set to NULL.

// Initially, all next pointers are set to NULL.

// Follow up:

// You may only use constant extra space.
// Recursive approach is fine, you may assume implicit stack space does not
// count as extra space for this problem.

// Example 1:

// Input: root = [1,2,3,4,5,6,7]
// Output: [1,#,2,3,#,4,5,6,7,#]
// Explanation: Given the above perfect binary tree (Figure A), your function
// should populate each next pointer to point to its next right node, just like
// in Figure B. The serialized output is in level order as connected by the next
// pointers, with '#' signifying the end of each level.

// Constraints:

// The number of nodes in the given tree is less than 4096.
// -1000 <= node.val <= 1000

#include <math.h>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Node {
   public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
   public:
    Node* connect(Node* root) {
        if (root == NULL) {
            return root;
        }
        vector<Node*> A = {root};
        int k = 1;
        Node* Reroot = root;
        while (k != 0) {
            k--;
            root = A[0];
            A.erase(A.begin());
            if (root->left != nullptr) {
                A.push_back(root->left);
            }
            if (root->right != nullptr) {
                A.push_back(root->right);
            }
            if (k == 0) {
                k = A.size();
                if (k == 0) {
                    return false;
                }
                for (int i = 0; i < k - 1; i++) {
                    A[i]->next = A[i + 1];
                }
            }
        }
        return Reroot;
    }
};