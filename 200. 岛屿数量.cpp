class Solution {
public:
    // 对网格中的每个点调用dfs
    int numIslands(vector<vector<char>>& grid) {
        this->ans = 0;
        this->rows = grid.size();
        this->cols = grid[0].size();
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == '1') {
                    dfs(grid, i, j);
                    ans++;
                }
            }
        }

        return ans;
    }

    // 由于是从上往下，从左往右遍历的，所以可以保证row之前的行都是0，col之前的列都是0
    void dfs(vector<vector<char>>& grid, int row, int col) {
        if (row < 0 || col < 0 || row == rows || col == cols) return;
        if (grid[row][col] == '0') return;
        grid[row][col] = '0';
        // 向上下左右四个方向遍历
        dfs(grid, row + 1, col);
        dfs(grid, row, col + 1);
        dfs(grid, row - 1, col);
        dfs(grid, row, col - 1);
    }

private:
    int ans;
    int rows, cols;
};