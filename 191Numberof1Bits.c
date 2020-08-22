uint32_t getbit(uint32_t num, int pos) {
    uint32_t i = 1;
    if (num & (i << (pos - 1))) {
        return 1;
    } else {
        return 0;
    }
}

int hammingWeight(uint32_t n) {
    int result = 0;
    for (int i = 1; i <= 32; i++) {
        if (getbit(n, i)) {
            result++;
        }
    }
    return result;
}