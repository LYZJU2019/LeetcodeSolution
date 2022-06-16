class Solution {
public:
    /**
     * two pointers: sp and fp
     * fp proceeds when reading elements in nums
     * sp always points to the left-most zero in nums
     * when nums[fp] != 0, swap nums[fp] and nums[sp] and forward sp
     */
    void moveZeroes(vector<int>& nums) {
        if (nums.empty()) return;
        int fp, sp;
        for (fp = 0, sp = 0; fp < nums.size(); fp++) {
            if (nums[fp] != 0) {
                swap(nums[fp], nums[sp++]);
            }
        }
    }
};