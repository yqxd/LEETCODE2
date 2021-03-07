#include <cmath>
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <cstdio>

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
    vector<vector<int>> A = {{1}};
    vector<vector<int>> B = {{2}};
    B.push_back(A[0]);
    for (auto i : B) {
        cout << i[0];
    }
}
