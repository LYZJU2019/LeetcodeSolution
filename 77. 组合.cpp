class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        // [1, ..., n] : choose 1, [2, ..., n] choose k-1
        //          or not choose 1, [2, ..., n] choose k
        vector<vector<int>> res;
        vector<int> path;
        dfs(res, path, 1, n, k);
        return res;
    }
    // begin starts from 1
    // *************** 定义：包括之前的选择，总共选择k个，但是只能从nums[begin]之后的元素中继续选择
    void dfs(vector<vector<int>> &res, vector<int> &path, int begin, int n, int k) {
        if (path.size() + (n - begin + 1) < k) return;

        if (path.size() == k) {
            res.push_back(path);
            return;
        }

        path.push_back(begin);
        dfs(res, path, begin+1, n, k);
        path.pop_back();
        dfs(res, path, begin+1, n, k);
    }

    // ************ 定义：在nums[begin]开始之后的元素中选择k个 ****************************
    void dfs(vector<vector<int>> &res, vector<int> &path, int begin, int n, int k) {
        if (n - begin + 1 < k) return;

        if (k == 0) {
            res.push_back(path);
            return;
        } 

        path.push_back(begin);
        dfs(res, path, begin+1, n, k-1);
        path.pop_back();
        dfs(res, path, begin+1, n, k);
    }
};