
#include <cstdio>
#include <iostream>

using namespace std;

void sum(int *a) {
    int idx = 0;
    for (int i = 8; i > 1; i >>= 2) {
        if (idx < i) {
            a[idx] += a[idx + i];
        }
        printf("%d", i);
    }
}

int main() {
    cout << "123" << (1 + 2) << '1' << endl;

}