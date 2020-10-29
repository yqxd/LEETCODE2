#include <math.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
typedef unsigned char byte;
using namespace std;

int main() {
    char A[] = "for i in range(1, n, 1):\nall 4";
    printf("%d\n", A);
    printf("%d\n", strlen(A));

    char str[] = "hello world";  //定义一个字符数组
    int len = strlen(str), i;  //获取字符数组的长度
    for (i = 0; i < len; i++) {
        printf("%c", str[i]);
    }
    printf("\n");
    char* p = str;  //定义一个指针变量，里面存放字符数组的首地址
    for (i = 0; i < len; i++) {
        printf("%c", *(p++));
    }  //使用指针的方式遍历字符数组，使用这种方式之后，指针p指向了数组以外的地址，有风险
    printf("\n");
    system("Pause");
}