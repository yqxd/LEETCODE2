#include <math.h>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
typedef unsigned char byte;
using namespace std;

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

void show_bytes(unsigned char* start, int len) {
    int i;
    for (i = 0; i < len; i++) {
        printf("%.2x", start[i]);
    }
}
typedef unsigned char byte;
int main() {
    struct TreeNode a1, a2, a3, a4, a5, a6, *b1 = &a1, *b2 = &a2, *b3 = &a3,
                                            *b4 = &a4, *b5 = &a5, *b6 = &a6;
    a1.val = 1;
    a2.val = 2;
    a3.val = 3;
    a4.val = 4;
    a5.val = 5;
    a6.val = 6;
    b1->left = b2;
    b1->right = b3;
    b2->left = b4;
    b2->right = b5;
    unsigned int val = 0xabcd9876;
    unsigned char* valp = (unsigned char*)&val;
    show_bytes(valp, 2);
    printf("%6d", 1);
    printf("%d", 1);
    int x = 0x7fffffff, y = 0x80000000, diff = (~x) + y + 1;
    cout << (((((y >> 31) ^ 0x1) & 0x1) & ((x >> 31) & 0x1)) |
             (((diff >> 31) ^ 0x1) & 0x1))
         << endl;
}