void rotate(int* nums, int numsSize, int k) {
    k = k % numsSize;
    if (k != 0) {
        int a[k];
        for (int i = 0; i < k; i++) {
            a[i] = nums[numsSize - k + i];
        }
        for (int i = 0; i < numsSize - k; i++) {
            nums[numsSize - i - 1] = nums[numsSize - i - 1 - k];
        }
        for (int i = 0; i < k; i++) {
            nums[i] = a[i];
        }
    }
}