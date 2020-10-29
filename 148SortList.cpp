#include <math.h>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
typedef unsigned char byte;
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
   public:
    ListNode* sortList(ListNode* head) {
        map<int, ListNode*> mp;
        vector<int> result;
        while(head != nullptr){
            mp[head->val] = head;
            result.push_back(head->val);
        }
        sort(result.begin(), result.end());
    }
};