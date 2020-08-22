int max(a, b);

int rob(int* nums, int numsSize) {
    if (numsSize == 1) {
        return nums[0];
    } else if (numsSize == 0) {
        return 0;
    } else if (numsSize == 2) {
        return max(nums[1], nums[0]);
    } else {
        nums[2] += nums[0];
        for (int i = 3; i < numsSize; i++) {
            nums[i] = max(nums[i - 2] + nums[i], nums[i - 3] + nums[i]);
        }
        return max(nums[numsSize - 1], nums[numsSize - 2]);
    }
}

int max(a, b) {
    if (a < b) {
        return b;
    } else {
        return a;
    }
}