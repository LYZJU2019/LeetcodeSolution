class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        this->n = n;
        vector<string> path(n, string(n, '.'));
        dfs(path, 0);
        return ans;
    }

    // 尝试在第row行放置皇后
    void dfs(vector<string> &path, int row) {
        if (row == n) {
            ans.push_back(path);
            return;
        }

        for (int col = 0; col < n; col++) {
            if (!IsValid(path, row, col)) continue;
            path[row][col] = 'Q';
            dfs(path, row + 1);
            path[row][col] = '.';
        }
    }

    bool IsValid(vector<string> &path, int row, int col) {
        // 检查同一行
        for (int j = col; j >= 0; j--) {
            if (path[row][j] == 'Q') return false;
        }

        // 检查同一列
        for (int i = row; i >= 0; i--) {
            if (path[i][col] == 'Q') return false;
        }

        // 检查对角线
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if (path[i][j] == 'Q') return false;
        }

        for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
            if (path[i][j] == 'Q') return false;
        }
        return true;
    }

private:
    vector<vector<string>> ans;
    int n;
};