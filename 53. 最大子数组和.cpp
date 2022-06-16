class Solution {
public:
    /**
     * 从左到右遍历每一个元素，记录当前子数组和，不断更新最大和
     * 如果发现子数组的和小于0，丢弃前面的全部
     *（这是因为假如a[i] < 0且a[j] + a[j+1] + ... + a[i] < 0，那么使子数组的和最大的子数组一定不包括a[i]）
     */
    int maxSubArray(vector<int>& nums) {
        int maxSum = -10005;
        int runningSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            maxSum = max(maxSum, nums[i]);
            runningSum += nums[i];
            if (runningSum < 0) runningSum = 0;
            else maxSum = max(maxSum, runningSum);
        }

        return maxSum;
    }
};