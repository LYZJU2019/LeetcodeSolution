class Solution {
public:
    // ***************************************************************************************
    // ***********************************前缀最大和后缀最大************************************
    // ***************************************************************************************
    int trap(vector<int>& height) {
        int n = height.size();
        int preMax[n], postMax[n];
        preMax[0] = height[0]; postMax[n-1] = height[n-1];
        for (int i = 1; i < n; i++) 
            preMax[i] = max(preMax[i-1], height[i]);
        for (int i = n-2; i >= 0; i--)
            postMax[i] = max(postMax[i+1], height[i]);

        int ans = 0;
        for (int i = 1; i <= n-2; i++) {
            ans += max(min(preMax[i], postMax[i]) - height[i], 0);
        }
        return ans;
    }
    
    // **************************************************************************************
    // *****************************************单调栈解法************************************
    // **************************************************************************************
    // 单调栈，栈单调递减
    // 如果单调性被破坏，弹栈
    // 将水看成横块，其中底的高度是heights[i]，顶的高度是两边柱子的高度的最小值，宽度为累计宽度
    int trap(vector<int>& heights) {
        stack<Rect> s;
        int ans = 0;
        for (int height : heights) {
            // 单调性被破坏
            int accu_width = 0;
            while (!s.empty() && s.top().height < height) {
                accu_width += s.top().width;
                int bottom = s.top().height;
                s.pop();
                if (s.empty()) break;
                int up = min(height, s.top().height); 
                ans += accu_width * (up - bottom);
            }

            s.push({height, accu_width + 1});
        }

        return ans;
    }

private:
    struct Rect {
        int height;
        int width;
    };
};