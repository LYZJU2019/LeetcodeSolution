class Solution {
public:
    int totalNQueens(int n) {
        this->ans = 0;
        this->n = n;
        board = vector<string>(n, string(n, '.'));
        dfs(0);
        return ans;
    }

    // 尝试在第row行及其之后的位置放置皇后
    void dfs(int row) {
        if (row == n) {
            ans++;
            return;
        }

        for (int col = 0; col < n; col++) {
            if (IsValid(row, col)) {
                board[row][col] = 'Q';
                dfs(row + 1);
                board[row][col] = '.';
            }
        }
    }

    bool IsValid(int row, int col) {
        // 检查这一行
        for (int j = col; j >= 0; j--) {
            if (board[row][j] == 'Q') return false;
        }

        // 检查这一列
        for (int i = row; i >= 0; i--) {
            if (board[i][col] == 'Q') return false;
        }

        // 检查对角线
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') return false;
        }

        for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q') return false;
        }

        return true;
    }

private:
    vector<string> board;
    int ans;
    int n;
};