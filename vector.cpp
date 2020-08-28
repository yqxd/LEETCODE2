#include <math.h>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>
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

int main() {
    vector<int> A = {1, 2, 3, 4, 5, 6, 7, 8}, B, C;
    for (auto i : A)
        cout << i;
    printf("\n");
    std::reverse(A.begin(), A.end());  // 内部倒序
    for (auto i : A)
        cout << i;
    printf("\n");
    B.swap(A);  // 外部赋值
    for (auto i : B)
        cout << i;
    printf("\n");
    B.clear();  // 清空
    for (auto i : B) {
        cout << i;
    }
    A = {1, 2, 3, 4, 5, 6, 7, 8};
    printf("\n");
    B = {1};
    B.assign(A.begin(), A.begin() + 1);  // 外部部分赋值
    for (auto i : B) {
        cout << i;
    }
    printf("\n");
    A = {1, 2, 3, 4, 5, 6, 7};  // 内部重新赋值
    for (auto i : A)
        cout << i;
    printf("\n");
    system("Pause");
}