class Solution {
public:
    /**
     * 题目只需返回元素，不要求位置，所以可以对原数组nums排序
     * 第一个元素a必须小于等于0，然后转化为两数之和（b+c=-a）
     * 去重：当a等于nums[i]时，下一个a应该是nums[j]，j > i且j是使nums[j] != nums[i]的最小的j
     */
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.size() < 3)
            return res;
            
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2 && nums[i] <= 0; i++) {
            if (i > 0 && nums[i] == nums[i-1])
                continue;
            
            // find b and c such that b + c = -a
            int second = i + 1, third = nums.size() - 1;
            while (second != third) {
                if (second > i + 1 && nums[second] == nums[second-1]) {
                    second++;
                    continue;
                }
                if (nums[second] + nums[third] == -nums[i]) {
                    res.push_back({nums[i], nums[second], nums[third]});
                    second++;
                } else if (nums[second] + nums[third] > -nums[i]) {
                    third--;
                } else {
                    second++;
                }
            }
        }

        return res;
    }
};