int maxProfit(int* prices, int pricesSize) {
    if (pricesSize <= 1) {
        return 0;
    }
    int head = 0;
    int max = prices[1] - prices[0];
    int min = prices[0];
    for (int tail = 2; tail < pricesSize; tail++) {
        if (min > prices[tail - 1]) {
            min = prices[tail - 1];
        }
        if (max < prices[tail] - min) {
            max = prices[tail] - min;
        }
    }
    if (max < 0) {
        return 0;
    }
    return max;
}