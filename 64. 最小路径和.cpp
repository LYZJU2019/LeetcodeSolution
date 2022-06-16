class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int dp[201][201];
        
        int rows = grid.size(), cols = grid[0].size();

        dp[rows][cols] = grid[rows-1][cols-1]; 
        // init last colomn
        for (int i = rows - 1; i >= 1; i--) 
            dp[i][cols] = dp[i+1][cols] + grid[i-1][cols-1];
        
        // init last row
        for (int j = cols - 1; j >= 1; j--) 
            dp[rows][j] = dp[rows][j+1] + grid[rows-1][j-1];
        
        for (int i = rows - 1; i >= 1; i--) {
            for (int j = cols - 1; j >= 1; j--) {
                dp[i][j] = std::min(dp[i+1][j], dp[i][j+1]) + grid[i-1][j-1];
            }
        }

        return dp[1][1];
    }
};