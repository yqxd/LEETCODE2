#include <algorithm>
#include <iostream>
#include <vector>
#include "map"

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {
    }
};

// Given a linked list, return the node where the cycle begins. If there is no
// cycle, return null.

// To represent a cycle in the given linked list, we use an integer pos which
// represents the position (0-indexed) in the linked list where tail connects
// to. If pos is -1, then there is no cycle in the linked list.

// Note: Do not modify the linked list.

// Example 1:

// Input: head = [3,2,0,-4], pos = 1
// Output: tail connects to node index 1
// Explanation: There is a cycle in the linked list, where tail connects to the
// second node.

// Example 2:

// Input: head = [1,2], pos = 0
// Output: tail connects to node index 0
// Explanation: There is a cycle in the linked list, where tail connects to the
// first node.

// Example 3:

// Input: head = [1], pos = -1
// Output: no cycle
// Explanation: There is no cycle in the linked list.

// Follow-up:
// Can you solve it without using extra space?

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        map<int, bool> M;
        while (head != NULL) {
            if (M.find(head->val) != M.end()) {
                return head;
            } else {
                M[head->val] = true;
            }
            head = head->next;
        }
        return NULL;
    }
};

int main() {
    Solution A;
    ListNode a = {3}, b = {2}, c = {0}, d = {4};
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &b;
    printf("%d", A.detectCycle(&a)->val);
}