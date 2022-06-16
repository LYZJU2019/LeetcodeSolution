class Solution {
public:
    // 先求矩阵前缀和，然后枚举子矩阵的上下边界，再枚举子矩阵的右边界，左边界通过哈希表查找得到
    // 当矩阵的上下边界固定时，相当于在前缀和数组中的找到两个数，使得差值等于target
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        // 计算二维前缀和
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<vector<int>> sum(rows+1, vector<int>(cols+1, 0));
        for (int row = 1; row <= rows; row++) {
            for (int col = 1; col <= cols; col++) {
                sum[row][col] = sum[row-1][col] + sum[row][col-1] - sum[row-1][col-1] + matrix[row-1][col-1];
            }
        }

        int ans = 0;
        // 枚举矩阵上下边界
        for (int top = 1; top <= rows; top++) {
            for (int bottom = top; bottom <= rows; bottom++) {
                // 以原矩阵左边界为左边界的矩阵和：数量
                unordered_map<int, int> map;
                for (int right = 1; right <= cols; right++) {
                    int curSum = sum[bottom][right] - sum[top-1][right];
                    if (curSum == target) ans++;
                    if (map.find(curSum - target) != map.end()) ans += map[curSum - target];
                    map[curSum]++;
                }
            }
        }

        return ans;
    }
};