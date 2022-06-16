class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        used = vector<bool>(nums.size(), false);
        vector<int> path;
        sort(nums.begin(), nums.end());
        dfs(path, nums);
        return res;
    }

    void dfs(vector<int> &path, vector<int> &nums) {
        if (path.size() == nums.size()) {
            res.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i-1] && !used[i-1])
                continue;
                
            if (!used[i]) {
                path.push_back(nums[i]);
                used[i] = true;
                dfs(path, nums);
                used[i] = false;
                path.pop_back();
            }
        }
    }

private:
    vector<vector<int>> res;
    vector<bool> used;
};