#include <stdio.h>
int maxProfit(int* prices, int pricesSize) {
    int max1 = 0, max2 = 0, formal = 0, head = 0, min = 0;
    int max = 0;
    for (int i = 0; i < pricesSize - 1; i++) {
        for (int j = 0; j < i; j++) {
            if (max1 < prices[i] - prices[j]) {
                max1 = prices[i] - prices[j];
            }
        }
        max2 = prices[i + 1] - prices[i];
        min = prices[i];
        for (int tail = i + 1; tail < pricesSize; tail++) {
            if (min > prices[tail]) {
                min = prices[tail];
            }
            if (max2 < prices[tail] - min) {
                max2 = prices[tail] - min;
            }
        }
        if (max2 < 0) {
            max2 = 0;
        }
        if (max1 + max2 > max) {
            max = max1 + max2;
        }
        max1 = 0;
    }
    return max;
}