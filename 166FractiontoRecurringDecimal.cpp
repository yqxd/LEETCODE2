//
// Created by lenovo on 2021/10/18.
//

//Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.
//
//If the fractional part is repeating, enclose the repeating part in parentheses.
//
//If multiple answers are possible, return any of them.
//
//It is guaranteed that the length of the answer string is less than 104 for all the given inputs.
//
//
//
//Example 1:
//
//Input: numerator = 1, denominator = 2
//Output: "0.5"
//Example 2:
//
//Input: numerator = 2, denominator = 1
//Output: "2"
//Example 3:
//
//Input: numerator = 2, denominator = 3
//Output: "0.(6)"
//Example 4:
//
//Input: numerator = 4, denominator = 333
//Output: "0.(012)"
//Example 5:
//
//Input: numerator = 1, denominator = 5
//Output: "0.2"

#include <cmath>
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include<queue>
#include<vector>
#include "stack"
#include "map"

using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        unsigned long num = labs(numerator), den = labs(denominator);
        string result = to_string(num / den);
        if ((numerator < 0 && denominator > 0) || (numerator > 0 && denominator < 0)) {
            result.insert(0, 1, '-');
        }
        unsigned long long shang = num % den, index;
        map<unsigned long long, int> m;
        if (shang != 0) {
            result += '.';
            index = result.size();
            while (shang != 0) {
                if (m.find(shang) == m.end()) {
                    m[shang] = result.size();
                } else {
                    result.insert(m[shang], 1, '(');
                    result += ')';
                    return result;
                }
                shang *= 10;
                result += (shang / den + 48);
                shang = shang % den;
            }
        }
        return result;
    }
};

int main() {
    Solution A;
    cout <<
         A.fractionToDecimal(-1,
                             -2147483648);
}

































