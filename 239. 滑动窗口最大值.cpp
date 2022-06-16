class Solution {
public:
    // **************************************************************************
    // **********************************单调队列*********************************
    // ***************************************************************************
    // 当一个数进窗口的时间比较早，而且小于后面进窗口的数，那么这个数就一定不可能是最大值，可以从队列中移走
    // 队列是单调递减的
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> queue;  // 存放index
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++) {
            // 窗口移动，将出界的数移出队列（只有队列前面的数有可能出界）
            while (!queue.empty() && queue.front() <= i - k) queue.pop_front();
            // 将小于nums[i]的数踢出队列（从队列后面剔除）
            while (!queue.empty() && nums[queue.back()] < nums[i]) queue.pop_back();
            // 从back放进queue
            queue.push_back(i);

            if (i >= k - 1) {
                ans.push_back(nums[queue.front()]);
            }
        }

        return ans;
    }
    // **************************************************************
    // ************************堆实现********************************
    // *************************************************************
    // 堆中存储idx，需要重写comparator函数
    struct Node {
        int idx;
        int val;
    };

    class Mycomparator {
    public:
        bool operator()(Node left, Node right) {
            return left.val < right.val;
        }
    };

    vector<int> maxSlidingWindow(vector<int>& nums, int k) { 
        priority_queue<Node, vector<Node>, Mycomparator> pq;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            pq.push({i, nums[i]});
            // 开始输出答案
            if (i >= k - 1) {
                // 排除出界的答案
                while (pq.top().idx <= i - k) pq.pop();
                ans.push_back(pq.top().val);
            }
        }

        return ans;
    }
};