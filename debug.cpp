#include <cmath>
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <cstdio>
#include "map"
#include "graphics.h"

typedef unsigned char byte;
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

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


using namespace std;


#include <graphics.h>


int main() {
//    int gdriver, gmode;
//    gdriver=600;
//    gmode=800;
//    initgraph(&gdriver, &gmode, (char*)"");
//    closegraph();
    cout << 1;
    return 0;
}