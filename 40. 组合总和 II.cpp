class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        this->nums = candidates;
        this->n = candidates.size();
        sort(nums.begin(), nums.end());
        vector<int> temp;
        dfs(temp, 0, target);
        return ans;
    }

    void dfs(vector<int> &temp, int begin, int target) {
        if (target == 0) {
            ans.push_back(temp);
            return;
        }

        if (begin == n || target <= 0) return;

        for (int i = begin; i < n; i++) {
            if (i > begin && nums[i] == nums[i-1])
                continue;
                
            temp.push_back(nums[i]);
            dfs(temp, i + 1, target - nums[i]);
            temp.pop_back();
        }
    }

private:
    vector<int> nums;
    int n;
    vector<vector<int>> ans;
};