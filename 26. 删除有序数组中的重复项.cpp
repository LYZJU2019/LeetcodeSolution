class Solution {
public:
    /**
     * Define two pointers (fast and slow)
     * fast ptr increments when reading elements in nums
     * slow ptr increments when reading new elements
     */
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty() || nums.size() == 1) {
            return nums.size();
        }

        int fp, sp;
        for (fp = 1, sp = 0; fp < nums.size(); fp++) {
            if (nums[fp] != nums[sp]) {
                nums[++sp] = nums[fp]; 
            }
        }
        return sp + 1;
    }
};