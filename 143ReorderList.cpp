//
// Created by lenovo on 2021/9/25.
//

//You are given the head of a singly linked-list. The list can be represented as:
//
//L0 → L1 → … → Ln - 1 → Ln
//        Reorder the list to be on the following form:
//
//L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
//You may not modify the values in the list's nodes. Only nodes themselves may be changed.



struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


#include <algorithm>
#include <iostream>
#include <vector>
#include "map"

using namespace std;

class Solution {
public:
    void reorderList(ListNode *head) {
        vector<ListNode *> l;
        while (head != NULL) {
            l.push_back(head);
            head = head->next;
        }
        ListNode *L[l.size()];
        copy(l.begin(), l.end(), L);
        int begin = 0, end = l.size() - 1;
        while (end - begin >= 2) {
            L[begin++]->next = L[end];
            L[end--]->next = L[begin];
        }
        if (end > begin) {
            L[begin]->next = L[end];
            L[end]->next = NULL;
        } else {
            L[begin]->next = NULL;
        }
    }
};

int main() {
    ListNode a(1), b(2), c(3), d(4);
    a.next = &b;
    b.next = &c;
    c.next = &d;
    Solution A;
    ListNode *p = &a;
    A.reorderList(p);
    while (p != NULL) {
        printf("%d", p->val);
        p = p->next;
    }
}
