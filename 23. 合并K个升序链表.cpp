/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {

public:
    // *****************************************************************************
    // ****************************基于标准库中的堆实现*******************************
    // *****************************************************************************
    // 传入priority_queue的比较器，C++中priority_queue默认是大顶堆
    class MyComparator {
    public:
        bool operator()(ListNode *lhs, ListNode *rhs) {
            return lhs->val > rhs->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *protect = new ListNode(0, nullptr);
        ListNode *prev = protect;
        priority_queue<ListNode*, vector<ListNode *>, MyComparator> pq;

        for (ListNode *node : lists) {
            if (node != nullptr)
                pq.push(node);
        }
        
        while (!pq.empty()) {
            ListNode *next = pq.top();
            pq.pop();
            if (next->next != nullptr)
                pq.push(next->next);
            prev->next = next;
            prev = prev->next;
        }
        return protect->next;
    }
    // **************************************        ******************************************************
    // ************************************** 分治法  ******************************************************
    // ***************************************       ********************************************************
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return helper(lists, 0, lists.size() - 1);
    }

    // 将lists中从begin开始到end结束，共计(end-begin+1)个链表合并，返回合并后的链表头节点
    ListNode *helper(vector<ListNode *> &lists, int begin, int end) {
        if (begin > end) {
            return nullptr;
        }

        if (begin == end) {
            return lists[begin];
        }
        // 将左边k/2个链表合并，头节点为left
        ListNode *left = helper(lists, begin, begin + (end - begin) / 2);
        // 将右边k/2个链表合并，头节点为right
        ListNode *right = helper(lists, begin + (end - begin) / 2 + 1, end);

        // 将left和right合并得到结果链表
        ListNode *protect = new ListNode(0, nullptr);
        ListNode *cur = protect;
        while (left != nullptr || right != nullptr) {
            if (left != nullptr && right != nullptr) {
                if (left->val > right->val) {
                    cur->next = right;
                    right = right->next;
                } else {
                    cur->next = left;
                    left = left->next;
                }
            } else if (left == nullptr) {
                cur->next = right;
                right = right->next;
            } else {
                cur->next = left;
                left = left->next;
            }
            cur = cur->next;
        }

        return protect->next;
    }

    // *****************************************************************************************
    // ***************************************基于手写的堆实现************************************
    // *****************************************************************************************
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        BinaryHeap Myheap;
        for (ListNode *head: lists) {
            if (head != nullptr) Myheap.insert(head);
        }

        ListNode *protect = new ListNode(0, nullptr);
        ListNode *cur = protect;
        while (!Myheap.empty()) {
            ListNode *next = Myheap.getMin();
            Myheap.deleteMin();
            cur->next = next;
            cur = cur->next;
            if (next->next != nullptr) {
                Myheap.insert(next->next);
            }
        }

        return protect->next;
    }

    // 手写小顶堆
    class BinaryHeap {
    public:
        BinaryHeap() {
            heap = vector<ListNode *>(1, nullptr);
        }

        bool empty() {
            return heap.size() == 1;
        }

        ListNode *getMin() {
            return heap[1];
        }

        void deleteMin() {
            heap[1] = heap[heap.size() - 1];
            heap.pop_back();
            heapifyDown(1);
        }

        void insert(ListNode *node) {
            heap.push_back(node);
            heapifyUp(heap.size() - 1);
        }
    private:
        vector<ListNode *> heap;
        // 只要当前的结点大于任意一个孩子，就往下交换
        void heapifyDown(int idx) {
            int smallest = idx;
            int lc;
            while ((lc = idx * 2) < heap.size()) {
                if (heap[lc]->val < heap[smallest]->val)
                    smallest = lc;
                int rc = idx * 2 + 1;
                if (rc < heap.size() && heap[rc]->val < heap[smallest]->val)
                    smallest = rc;
                if (smallest == idx)
                    break;
                swap(heap[idx], heap[smallest]);
                idx = smallest;
            }
        }

        void heapifyUp(int idx) {
            while (idx > 1) {
                if (heap[idx / 2]->val < heap[idx]->val)
                    break;
                swap(heap[idx], heap[idx / 2]);
                idx /= 2;
            }
        }
    };
};