class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        int dp[301][301];

        int max_area = 0;
        // init last row
        for (int j = 1; j <= cols; j++) {
            dp[rows][j] = matrix[rows-1][j-1] - '0';
            if (dp[rows][j] == 1) max_area = 1;
        }
        // init last col
        for (int i = 1; i <= rows; i++) {
            dp[i][cols] = matrix[i-1][cols-1] - '0';
            if (dp[i][cols] == 1) max_area = 1;
        }
        for (int i = rows - 1; i >= 1; i--) {
            for (int j = cols - 1; j >= 1; j--) {
                if (matrix[i-1][j-1] == '0')
                    dp[i][j] = 0;
                else {
                    int side = min(dp[i+1][j], min(dp[i][j+1], dp[i+1][j+1])) + 1;
                    dp[i][j] = side;
                    max_area = max(max_area, side * side);
                }
            }
        }

        return max_area;
    }
};