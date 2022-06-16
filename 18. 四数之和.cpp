class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        this->nums = nums;
        if (nums.size() < 4) return ans;
        for (int i = 0; i < nums.size() - 3; i++) {
            if (i > 0 && nums[i] == nums[i-1])
                continue;
            auto res = threeSum(i + 1, nums.size() - 1, target - nums[i]);
            for (vector<int> &vec: res) {
                vec.push_back(nums[i]);
                ans.push_back(vec);
            }
        }

        return ans;
    }

    vector<vector<int>> threeSum(int begin, int end, int target) {
        vector<vector<int>> res;
        for (int i = begin; i <= end - 2; i++) {
            if (i > begin && nums[i] == nums[i-1])
                continue;
            
            int left = i + 1;
            int right = end;
            int old_left, old_right;
            while (left < right) {
                if (nums[left] + nums[right] <= target - nums[i]) {
                    if (nums[left] + nums[right] == target - nums[i])
                        res.push_back({nums[i], nums[left], nums[right]});
                    old_left = left;
                    while (left < end && nums[++left] == nums[old_left]);
                }
                else {
                    old_right = right;
                    while (right > begin && nums[--right] == nums[old_right]);
                } 
            }
        }
        return res;
    }

private:
    vector<int> nums;
};