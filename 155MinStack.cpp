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
using namespace std;

class MinStack {
   public:
    /** initialize your data structure here. */
    vector<int> A;
    vector<int> B;
    MinStack() {
        A = {};
        B = {};
    }

    void push(int x) {
        int i = 0;
        B.pop_back();
        for (i = A.size() - 1; i >= 0; i--) {
            if (A[i] >= x) {
                A.insert(A.begin() + i + 1, x);
                break;
            }
        }
    }

    void pop() { A.pop_back(); }

    int top() { return top[top.size() - 1]; }

    int getMin() {}
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