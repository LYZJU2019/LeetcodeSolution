class Solution {
public:
    /**
     * 建立一个映射map，key为数组元素，value是一个三元组（times, i, j），储存元素出现次数times，
     * 第一次出现的下标i，最后一次出现的下标j
     * 找到times最大的元组，
     * 和原数组有相同的度的最短连续子数组的长度就是（j-i+1）
     */
    int findShortestSubArray(vector<int>& nums) {
        int maxTime = 0;
        unordered_map<int, vector<int>> map;
        int ans = 50005;

        for (int i = 0; i < nums.size(); i++) {
            if (map.find(nums[i]) == map.end()) {
                map[nums[i]].push_back(1);
                map[nums[i]].push_back(i);
                map[nums[i]].push_back(i);
            } else {
                map[nums[i]][0]++;
                map[nums[i]][2] = i;
            }
            maxTime = max(maxTime, map[nums[i]][0]);
        }

        for (auto KV_pair : map) {
            if (KV_pair.second[0] == maxTime)
                ans = min(ans, KV_pair.second[2] - KV_pair.second[1] + 1);
        }

        return ans;
    }
};