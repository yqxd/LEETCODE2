uint32_t getbit(uint32_t num, int pos) {
    uint32_t i = 1;
    if (num & (i << (pos - 1))) {
        return 1;
    } else {
        return 0;
    }
}

uint32_t reverseBits(uint32_t n) {
    uint32_t s = 0;
    for (int i = 1; i <= 32; i++) {
        s = s | (getbit(n, i) << (32 - i));
    }
    return s;
}