class Solution {
   public:
    vector<int> getRow(int rowIndex) {
        vector<int> Row(rowIndex + 1, 0);
        Row[0] = 1;
        for (int i = 0; i < rowIndex; i = i + 1) {
            for (int j = i + 1; j >= 1; j = j - 1) {
                Row[j] = Row[j] + Row[j - 1];
            }
        }
        return Row;
    }
};