class Solution {
public:
    /**
     *
     * Hashmap (unordered)
     * key: elem, Value: index
     * insert into hashmap iff its complement is not in the map (avoid duplication)
     */
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashmap {};
        for (int i = 0; i < nums.size(); i++) {
            if (hashmap.find(target - nums[i]) != hashmap.end()) {
                return vector<int> {i, hashmap[target - nums[i]]};
            }
            hashmap[nums[i]] = i;
        }

        return vector<int>();
    }
};