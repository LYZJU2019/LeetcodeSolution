class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res; // answer set
        if (nums.empty()) {
            return res;
        }
        vector<int> path;
        dfs(res, path, nums, 0);
        return res;
    }

    void dfs(vector<vector<int>> &res, vector<int> &path, vector<int> &nums, int start) {
        if (start == nums.size()) {
            res.push_back(path);
            return;
        }

        path.push_back(nums[start]);
        dfs(res, path, nums, start + 1);    // contains the current element
        path.pop_back();
        dfs(res, path, nums, start + 1);    // exclude the current element
    }
};