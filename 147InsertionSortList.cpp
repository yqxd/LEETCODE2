//
// Created by lenovo on 2021/9/27.
//

//Given the head of a singly linked list, sort the list using insertion sort, and return the sorted list's head.
//
//The steps of the insertion sort algorithm:
//
//Insertion sort iterates, consuming one input element each repetition and growing a sorted output list.
//At each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list and inserts it there.
//It repeats until no input elements remain.
//The following is a graphical example of the insertion sort algorithm. The partially sorted list (black) initially contains only the first element in the list. One element (red) is removed from the input data and inserted in-place into the sorted list with each iteration.


#include "algorithm"
#include "iostream"
#include "vector"
#include "map"

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        vector<ListNode *> vec;
        ListNode *temp;
        while (head != NULL) {
            vec.push_back(head);
            head = head->next;
        }
        for (int i = 1; i < vec.size(); i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (vec[j]->val > vec[j + 1]->val) {
                    temp = vec[j];
                    vec[j] = vec[j + 1];
                    vec[j + 1] = temp;
                } else {
                    break;
                }
            }
        }
        for (int i = 1; i < vec.size(); i++) {
            vec[i - 1]->next = vec[i];
        }
        vec[vec.size() - 1]->next = NULL;
        return vec[0];
    }
};

int main() {
    ListNode *a = new ListNode(4), *b = new ListNode(2), *c = new ListNode(1), *d = new ListNode(3);
    a->next = b;
    b->next = c;
    c->next = d;
    Solution A;
    A.insertionSortList(a);
    while (a != NULL) {
        cout << a->val << endl;
        a = a->next;
    }
}
