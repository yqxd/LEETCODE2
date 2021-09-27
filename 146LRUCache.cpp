//
// Created by lenovo on 2021/9/25.
//

//Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.
//
//Implement the LRUCache class:
//
//        LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
//int get(int key) Return the value of the key if the key exists, otherwise return -1.
//void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
//The functions get and put must each run in O(1) average time complexity.
//
//
//
//Example 1:
//
//Input
//["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
//[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
//Output
//[null, null, null, 1, null, -1, null, -1, 3, 4]
//
//Explanation
//        LRUCache lRUCache = new LRUCache(2);
//lRUCache.put(1, 1); // cache is {1=1}
//lRUCache.put(2, 2); // cache is {1=1, 2=2}
//lRUCache.get(1);    // return 1
//lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
//lRUCache.get(2);    // returns -1 (not found)
//lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
//lRUCache.get(1);    // return -1 (not found)
//lRUCache.get(3);    // return 3
//lRUCache.get(4);    // return 4

#include "algorithm"
#include "iostream"
#include "vector"
#include "map"

using namespace std;

class LRUCache {
public:
    map<int, long *> key2value_priority;
    map<long, int> priority2key;
    long before = 0, current = 0;
    int available;

    LRUCache(int capacity) {
        available = capacity;
    }

    int get(int key) {
        if (key2value_priority.find(key) != key2value_priority.end()) {
            key2value_priority[key][1] = before--;
            return key2value_priority[key][0];
        } else {
            return -1;
        }
    }

    void put(int key, int value) {
        if (available == 0) {
            while (true) {
                if (priority2key.find(current) == priority2key.end()) {
                    current--;
                } else {
                    break;
                }
            }
            key2value_priority.erase(priority2key[current]);
            priority2key.erase(current--);
            priority2key[before] = key;
            key2value_priority[key] = new long[2]{value, before--};
        } else {
            key2value_priority[key] = new long[2]{value, current};
            priority2key[current++] = key;
            available -= 1;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

//class LRUCache {
//public:
//    class Node{
//        //public:
//        int key;
//        int val;
//        Node *next;
//        Node *prev;
//
//        Node(int key, int val){
//            this->key = key;
//            this->val = val;
//            next = nullptr;
//            prev = nullptr;
//        }
//        friend class LRUCache;
//    };
//
//
//    int cap;
//    unordered_map<int, Node*> mpp;
//    Node *head = new Node(-1, -1);
//    Node *tail = new Node(-1, -1);
//
//    LRUCache(int cap){
//        this->cap = cap;
//        head->next = tail;
//        tail->prev = head;
//    }
//
//    void add(Node *curr){
//        Node *temp = head->next;
//        curr->prev = head;
//        curr->next = temp;
//        temp->prev = curr;
//        head->next = curr;
//    }
//
//    void deleteNode(Node *curr){
//        Node *temp = curr->prev;
//        temp->next = curr->next;
//        curr->next->prev = temp;
//        //delete curr;
//    }
//
//    void put(int key, int val){
//        if(mpp.find(key) != mpp.end()){
//            Node *curr = mpp[key];
//            curr->val = val;
//            deleteNode(curr);
//            add(curr);
//            mpp[key] = head->next;
//        }
//        else if(mpp.size() == cap){
//            Node *curr = tail->prev;
//            mpp.erase(curr->key);
//            deleteNode(curr);
//            add(new Node(key, val));
//            mpp[key] = head->next;
//        }
//        else{
//            Node *newNode = new Node(key, val);
//            add(newNode);
//            mpp[key] = head->next;
//        }
//    }
//
//    int get(int key){
//        if(mpp.find(key) != mpp.end()){
//            Node *curr = mpp[key];
//            mpp.erase(key);
//            int res = curr->val;
//            deleteNode(curr);
//            add(curr);
//            mpp[key] = head->next;
//            return res;
//        }
//        return -1;
//    }
//
//};

int main() {
    LRUCache lRUCache(2);
    lRUCache.put(1, 1); // cache is {1=1}
    lRUCache.put(2, 2); // cache is {1=1, 2=2}
    printf("%d\n", lRUCache.get(1));    // return 1
    lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
    printf("%d\n", lRUCache.get(2));    // returns -1 (not found)
    lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
    printf("%d\n", lRUCache.get(1));    // return -1 (not found)
    printf("%d\n", lRUCache.get(3));    // return 3
    printf("%d\n", lRUCache.get(4));    // return 4
}