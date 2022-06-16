class Solution {
public:
    // 暴力做法：由小到大排序后取第k个元素
    // int findKthLargest(vector<int>& nums, int k) {
    //     sort(nums.begin(), nums.end());
    //     return nums[nums.size() - k];
    // }

    class comparator {
    public:
        bool operator()(int x, int y) { return x > y; }
    };

    // 第K大的元素意味着有K-1个元素比它大
    // 用数组的前K个元素建立一个最小堆，注意扫描数组剩下的元素
    // 如果小于堆顶，忽略；否则取出堆顶，将该元素插入堆中
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, comparator> pq(nums.begin(), nums.begin() + k);
        for (int i = k; i < nums.size(); i++) {
            if (nums[i] > pq.top()) {
                pq.pop();
                pq.push(nums[i]);
            }
        }
        return pq.top();
    }  
    
};