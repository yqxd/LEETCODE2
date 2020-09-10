#include <math.h>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// Given the head of a singly linked list where elements are sorted in ascending
// order, convert it to a height balanced BST.

// For this problem, a height-balanced binary tree is defined as a binary tree
// in which the depth of the two subtrees of every node never differ by more
// than 1.

// Example 1:

// Input: head = [-10,-3,0,5,9]
// Output: [0,-3,9,-10,null,5]
// Explanation: One possible answer is [0,-3,9,-10,null,5], which represents the
// shown height balanced BST. Example 2:

// Input: head = []
// Output: []
// Example 3:

// Input: head = [0]
// Output: [0]
// Example 4:

// Input: head = [1,3]
// Output: [3,1]

// Constraints:

// The number of nodes in head is in the range [0, 2 * 104].
// -10^5 <= Node.val <= 10^5

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right) {}
};

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
   public:
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> A = {};
        while (head != nullptr) {
            A.push_back(head->val);
            head = head->next;
        }
        return sortedArrayToBST(A);
    }
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