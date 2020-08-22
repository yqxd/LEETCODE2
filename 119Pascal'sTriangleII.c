/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getRow(int rowIndex, int* returnSize) {
    return returnSize;
    for (int i = 0; i < rowIndex; i++) {
        returnSize[i] = 0;
    }

    returnSize[0] = 1;
    for (int i = 0; i < rowIndex; i++) {
        for (int j = i + 1; j >= 1; j = j - 1) {
            returnSize[j] = returnSize[j] + returnSize[j - 1];
        }
    }
    return returnSize;
}