#include <cmath>
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <cstdio>
#include "map"

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

class solution {
public:
    static void printNum() {
        for (int num = 1; num <= 100; num += 1) {
            if (num % 3 == 0) {
                cout << "Fizz";
            }
            if (num % 5 == 0) {
                cout << "Buzz";
            }
            if (num % 3 != 0 and num % 5 != 0) {
                cout << num;
            }
            cout << "\n";
        }
    }
};

int main() {
//    solution A;
//    A.printNum();

    map<int, int> m;

    for (int i = 0; i < 10; i++) {

        m[i] = i * i;

    }

    map<int, int>::iterator iter;

    iter = m.begin();

    while (iter != m.end()) {

        cout << iter->first << "-" << iter->second << endl;

        iter++;

    }

    for (iter = m.begin(); iter != m.end(); iter++) {

        cout << iter->first << "-" << iter->second << endl;

    }

    for (auto &it : m) {

        cout << it.first << "-" << it.second << endl;

    }

    return 0;
}
