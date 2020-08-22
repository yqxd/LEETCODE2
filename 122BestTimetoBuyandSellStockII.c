int maxProfit(int* prices, int pricesSize) {
    int sum = 0;
    int formal = prices[0];
    for (int i = 1; i < pricesSize; i++) {
        if (prices[i] < formal) {
            formal = prices[i];
        } else {
            sum += prices[i] - formal;
            formal = prices[i];
        }
    }
    return sum;
}