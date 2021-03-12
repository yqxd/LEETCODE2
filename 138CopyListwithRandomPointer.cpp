//
// Created by lenovo on 2021/3/10.
//

//A linked list of length n is given such that each node contains an additional random pointer, which could point to any node in the list, or null.
//
//Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, where each new node has its value set to the value of its corresponding original node. Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state. None of the pointers in the new list should point to nodes in the original list.
//
//For example, if there are two nodes X and Y in the original list, where X.random --> Y, then for the corresponding two nodes x and y in the copied list, x.random --> y.
//
//Return the head of the copied linked list.
//
//The linked list is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:
//
//val: an integer representing Node.val
//        random_index: the index of the node (range from 0 to n-1) that the random pointer points to, or null if it does not point to any node.
//Your code will only be given the head of the original linked list.
//
//
//
//Example 1:
//
//
//Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
//Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]
//Example 2:
//
//
//Input: head = [[1,1],[2,1]]
//Output: [[1,1],[2,1]]
//Example 3:
//
//
//
//Input: head = [[3,null],[3,0],[3,null]]
//Output: [[3,null],[3,0],[3,null]]
//Example 4:
//
//Input: head = []
//Output: []
//Explanation: The given linked list is empty (null pointer), so return null.
//
//
//Constraints:
//
//0 <= n <= 1000
//-10000 <= Node.val <= 10000
//Node.random is null or is pointing to some node in the linked list.

// Definition for a Node.

#include <cmath>
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>
#include <cstring>
#include <string>
#include <map>

using namespace std;

class Node {
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

//unordered_map<Node *, Node *> locMap;
//
//class Solution {
//public:
//
//    static Node *copyRandomList(Node *head) {
//        if (head == nullptr) {
//            return head;
//        } else {
//            locMap.clear();
//            copy(head);
//            for (auto &it:locMap) {
//                it.second->next = locMap[it.second->next];
//                it.second->random = locMap[it.second->random];
//            }
//            return locMap[head];
//        }
//    }
//
//    static void copy(Node *head) {
//        if (head == nullptr) {
//            return;
//        } else if (locMap[head] == nullptr) {
//            locMap[head] = new Node(head->val);
//            locMap[head]->random = head->random;
//            locMap[head]->next = head->next;
//            copy(head->random);
//            copy(head->next);
//        }
//    }
//};

class Solution {
public:
    Node *copyRandomList(Node *head) {
        Node *iter = head;
        Node *front = head;

        //Copy Nodes
        while (iter) {
            front = iter->next;
            Node *copy = new Node(iter->val);
            iter->next = copy;
            copy->next = front;
            iter = front;
        }
        //Copy Random pointers
        iter = head;
        while (iter) {
            if (iter->random) {
                iter->next->random = iter->random->next;
            }
            iter = iter->next->next;
        }
        //Creating a Dummy Node with all the Copy Nodes and Random pointers
        iter = head;
        Node *dummy = new Node(0);
        Node *copy = dummy;

        while (iter) {
            front = iter->next->next;
            copy->next = iter->next;
            iter->next = front;
            copy = copy->next;
            iter = front;
        }
        return dummy->next;
    }
};

int main() {
    Node *a1 = new Node(7);
    Node *a2 = new Node(13);
    Node *a3 = new Node(11);
    Node *a4 = new Node(10);
    Node *a5 = new Node(1);
    a1->next = a2;
    a2->next = a3;
    a3->next = a4;
    a4->next = a5;
    a5->next = nullptr;
    a1->random = nullptr;
    a2->random = a1;
    a3->random = a5;
    a4->random = a3;
    a5->random = a1;
    Node *b1 = Solution::copyRandomList(a1);
}