class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        // start from root node
        // you can choose nums.size() different elements as the first (mark that element)
        // drill down
        // unchoose, and unmark
        vector<vector<int>> res;
        if (nums.empty()) return res;
        marked = vector<bool>(nums.size(), false);
        vector<int> path;
        dfs(path, nums, res);
        return res;
    }

    void dfs(vector<int> &path, vector<int> &nums, vector<vector<int>> &res) {
        if (path.size() == nums.size()) {
            res.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (marked[i]) continue;
            path.push_back(nums[i]);
            marked[i] = true;
            dfs(path, nums, res);
            path.pop_back();
            marked[i] = false;
        }
    }

private:
    vector<bool> marked;
};