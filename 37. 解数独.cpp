class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        this->rows = board.size();
        this->cols = board[0].size();
        dfs(board, 0, 0);
    }

    // 从(row, col)处开始填入数字，从上到下，从左往右，返回成功与否（由于答案唯一，所以dfs返回值为bool）
    // 如果要求返回所有的答案，返回值为void，找到答案之后push进结果集里面
    // 否则将在返回时将被撤销！
    bool dfs(vector<vector<char>> &board, int row, int col) {
        if (col == cols) {
            if (row == rows - 1) return true;
            return dfs(board, row+1, 0);
        }

        // 如果当前位置有数，跳过当前位置继续往后填
        if (board[row][col] != '.') return dfs(board, row, col+1);

        // 依次尝试所有的可能
        for (int i = 1; i <= 9; i++) {
            // 检查该选择是否合法
            if (!IsValid(board, row, col, i)) continue;
            board[row][col] = i + '0';
            if (dfs(board, row, col+1)) return true;
            board[row][col] = '.';
        }

        // 所有的尝试都失败了，返回上一层（撤销这个位置之前的选择）
        return false;
    }

    bool IsValid(vector<vector<char>> &board, int row, int col, int num) {
        int row_gs = row / 3 * 3;  
        int col_gs = col / 3 * 3;
        // 检查行
        for (int j = 0; j < cols; j++) {
            if (board[row][j] == num + '0') return false;
        }
        // 检查列
        for (int i = 0; i < rows; i++) {
            if (board[i][col] == num + '0') return false;
        }
        // 检查3x3方格
        for (int i = row_gs; i < row_gs + 3; i++) {
            for (int j = col_gs; j < col_gs + 3; j++) {
                if (board[i][j] == num + '0') return false;
            }
        }

        return true;
    }

private:
    int rows;
    int cols;
};