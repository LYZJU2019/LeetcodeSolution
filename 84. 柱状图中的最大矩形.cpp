class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // ***********************************************************************************
        // ************************************* 暴力法 ***************************************
        // ***********************************************************************************
        // 面积最大的矩形的高度一定和其中某一根柱子的高度相同（那根柱子限制了矩形的高度）
        // 枚举每一根柱子，以此为矩形的高度，左右延申到最大宽度，求出面积
        // 更新最大面积
        // !这种解法复杂度是O(n^2)，会超出时间限制
        int maxArea = 0;
        for (int i = 0; i < heights.size(); i++) {
            int height = heights[i];
            int left = i - 1, right = i + 1;
            while (left >= 0 && heights[left] >= height) {
                left--;
            }
            while (right < heights.size() && heights[right] >= height) {
                right++;
            }
            maxArea = max(maxArea, height * (right - left - 1));
        }

        return maxArea;

        // ******************************************************************************
        // ************************************单调栈*************************************
        // ******************************************************************************
        // 以某一条柱子的x坐标为矩形的左边界，可以一直向右延申，直到其中某根柱子的高度小于该柱子
        // 维护一个单调栈，单调递增
        struct Rect {
            int height;
            int accu_width;  // 向左延申的最大宽度
        };

        stack<Rect> s;
        heights.push_back(0);
        int ans = 0;
        for (int i = 0; i < heights.size(); i++) {
            // 如果当前元素破坏了栈的单调性
            // 记录这跟柱子高的柱子的accu_width（这些柱子的最大延申宽度已经确定下来了，需要存起来）
            // 但是比这跟柱子矮的柱子的最大延申宽度还不确定（意思是这些柱子还可以继续向右延申）

            int accu_width = 0;  // 记录这根柱子向左延申的最大宽度
            while (!s.empty() && s.top().height > heights[i]) {
                accu_width += s.top().accu_width;  // 之前柱子向左延申的最大宽度 + 该柱子延申到之前柱子时的宽度 = 之前柱子可以左右延申的最大宽度
                ans = max(ans, s.top().height * accu_width);
                s.pop();
            }
            s.push({heights[i], accu_width + 1});
        }

        return ans;
    }
};