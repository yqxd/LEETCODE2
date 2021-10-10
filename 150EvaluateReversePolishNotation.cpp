//
// Created by lenovo on 2021/9/29.
//

//Evaluate the value of an arithmetic expression in Reverse Polish Notation.
//
//Valid operators are +, -, *, and /. Each operand may be an integer or another expression.
//
//Note that division between two integers should truncate toward zero.
//
//It is guaranteed that the given RPN expression is always valid. That means the expression would always evaluate to a result, and there will not be any division by zero operation.
//
//
//
//Example 1:
//
//Input: tokens = ["2","1","+","3","*"]
//Output: 9
//Explanation: ((2 + 1) * 3) = 9
//Example 2:
//
//Input: tokens = ["4","13","5","/","+"]
//Output: 6
//Explanation: (4 + (13 / 5)) = 6
//Example 3:
//
//Input: tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
//Output: 22
//Explanation: ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
//= ((10 * (6 / (12 * -11))) + 17) + 5
//= ((10 * (6 / -132)) + 17) + 5
//= ((10 * 0) + 17) + 5
//= (0 + 17) + 5
//= 17 + 5
//= 22

#include <math.h>
#include <algorithm>
#include <iostream>
#include <map>
#include <cstdlib>
#include <climits>
#include <unordered_map>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> stk;

        for (auto & token : tokens) {
            if (token != "+" && token != "-" && token != "*" && token != "/")
                stk.push(stoi(token));
            else {
                int num1 = stk.top();
                stk.pop();
                int num2 = stk.top();
                stk.pop();
                if (token == "+")
                    stk.push(num1 + num2);
                else if (token == "-")
                    stk.push(num2 - num1);
                else if (token == "*")
                    stk.push(num1 * num2);
                else
                    stk.push(num2 / num1);
            }
        }

        return stk.top();
    }
};

int main() {

}