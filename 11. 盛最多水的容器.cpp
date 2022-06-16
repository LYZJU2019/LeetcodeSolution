class Solution {
public:
    /**
     * 双指针，初始时左指针指向最左边的柱子，右指针指向最右边的柱子
     * 将限制其最大高度的指针向中间移动，移到第一个高的柱子
     * 重复
     */
    int maxArea(vector<int>& height) {
        int max_area = 0;
        int left = 0, right = height.size() - 1;
        while (left < right) {
            max_area = max(max_area, min(height[left], height[right]) * (right - left));
            // move left
            if (height[left] < height[right]) {
                int old_left = left;
                while (left < height.size() - 1 && height[++left] <= height[old_left]);
            } else {
                int old_right = right;
                while (right > 0 && height[--right] <= height[old_right]);
            }
        } 

        return max_area;
    }
};