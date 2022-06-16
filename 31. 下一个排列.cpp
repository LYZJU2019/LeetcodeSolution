class Solution {
public:
    /**
     * 将数组后面位置的大数和前面位置的小数交换，要求大数尽可能小，小数的位置尽可能靠后
     * 当一个数组是降序排列的时候，不存在这样的大数和小数
     * 当a[i] < a[i+1] 并且 a[i+1]之后的数组都是降序时，a[i]就是符合要求的小数，之后比a[i]大的最小数a[j]
     * 就是大数（此时符合大数尽可能小，小数尽可能靠后的要求）
     * 交换a[i]和a[j]
     * 此时将a[i+1]之后的数组按升序排序，所得到的排列一定比之前的大，并且一定是下一个排列
     */
    void nextPermutation(vector<int>& nums) {
        int small = -1, large = nums.size() - 1;
        for (int i = large; i >= 0; i--) {
            if (i < nums.size() - 1 && nums[i] < nums[i+1]) {
                small = i;
                break;
            }
        }
        if (small == -1) {
            sort(nums.begin(), nums.end());
            return;
        }
        large = findLarge(nums, small + 1, nums[small]);
        swap(nums[large], nums[small]);
        sort(nums.begin() + small + 1, nums.end());
    }

    // 从nums[begin]开始找到大于target的最小数，返回index
    int findLarge(vector<int> &nums, int begin, int target) {
        int i;
        for (i = begin; i < nums.size() && nums[i] > target; i++)
            ;
        return i - 1;
    }
};