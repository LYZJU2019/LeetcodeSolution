class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> candidate;
        this->n = candidates.size();
        this->nums = candidates;
        dfs(candidate, 0, target);
        return ans;
    }

    void dfs(vector<int> &candidate, int begin, int target) {
        if (target == 0) {
            ans.push_back(candidate);
            return;
        }
        if (begin == n || target < 0) return;

        for (int i = begin; i < n; i++) {
            candidate.push_back(nums[i]);
            dfs(candidate, i, target - nums[i]);
            candidate.pop_back();
        }
    }

private:
    vector<vector<int>> ans;
    vector<int> nums;
    int n;
};