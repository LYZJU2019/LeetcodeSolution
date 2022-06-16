class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        this->nums = nums;
        this->n = nums.size();
        vector<int> temp;
        dfs(temp, 0);
        return ans;
    }

    void dfs(vector<int> &temp, int i) {
        if (i == n) {
            ans.push_back(temp);
            return;
        }
        
        if (i == 0 || nums[i] != nums[i-1] || map[nums[i-1]]) {
            temp.push_back(nums[i]);
            map[nums[i]] = true;
            dfs(temp, i + 1);
            temp.pop_back();
            map[nums[i]] = false;
        }

        dfs(temp, i + 1);
    }

private:
    int n;
    vector<int> nums;
    vector<vector<int>> ans;
    unordered_map<int, bool> map;
};