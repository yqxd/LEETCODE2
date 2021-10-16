// Design a stack that supports push, pop, top, and retrieving the minimum
// element in constant time.

// push(x) -- Push element x onto stack.
// pop() -- Removes the element on top of the stack.
// top() -- Get the top element.
// getMin() -- Retrieve the minimum element in the stack.

// Example 1:

// Input
// ["MinStack","push","push","push","getMin","pop","top","getMin"]
// [[],[-2],[0],[-3],[],[],[],[]]

// Output
// [null,null,null,null,-3,null,0,-2]

// Explanation
// MinStack minStack = new MinStack();
// minStack.push(-2);
// minStack.push(0);
// minStack.push(-3);
// minStack.getMin(); // return -3
// minStack.pop();
// minStack.top();    // return 0
// minStack.getMin(); // return -2

// Constraints:

// Methods pop, top and getMin operations will always be called on non-empty
// stacks.

#include <math.h>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include<queue>
#include<vector>
#include "stack"

using namespace std;

class MinStack {
public:
    stack<int> data;
    stack<int> mindata;

    MinStack() {

    }

    void push(int val) {
        data.push(val);
        if (mindata.size() == 0 || val <= mindata.top()) {
            mindata.push(val);
        }

    }

    void pop() {
        int val = data.top();
        data.pop();
        if (val == mindata.top())
            mindata.pop();

    }

    int top() {
        return data.top();
    }

    int getMin() {
        return mindata.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main() {
    MinStack A;
}