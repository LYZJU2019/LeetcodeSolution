class Solution {
public:
    // *********************************************************************
    // ******************************暴力解法*******************************
    // *********************************************************************
    int maximalRectangle(vector<vector<char>>& matrix) {
        int dp[200][200];
        int rows = matrix.size(), cols = matrix[0].size();
        int max_area = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                // fill in the de table
                if (j == 0) {
                    dp[i][j] = matrix[i][j] - '0';
                }
                else if (matrix[i][j] == '0') {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = dp[i][j-1] + 1;
                }

                int min_cont = dp[i][j];
                int height;
                // 以（i,j）为矩形的右下角，不断向上延申，更新最大宽度，计算最大面积
                for (int k = i; k >= 0; k--) {
                    min_cont = min(min_cont, dp[k][j]);
                    height = i - k + 1;
                    max_area = max(max_area, min_cont * height);
                }
            }
        }

        return max_area;
    }
};