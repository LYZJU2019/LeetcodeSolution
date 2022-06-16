class Twitter {
public:
    Twitter() {
        this->time = 0;
        // 建立保护头节点
        for (int uid = 1; uid <= 500; uid++) {
            tweetList[uid] = new ListNode();
            tweetList[uid]->ts = -1;
        }
    }   
    
    void postTweet(int userId, int tweetId) {
        // 头插法
        ListNode *newtweet = new ListNode(tweetId, tweetList[userId]->next);
        newtweet->ts = time++;
        tweetList[userId]->next = newtweet;
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<ListNode *> nodeList;
        // 把自己加进去
        nodeList.push_back(tweetList[userId]->next);
        // 把该user的关注者加进去
        for (int followee : followList[userId]) {
            nodeList.push_back(tweetList[followee]->next);   // head的下一个节点就是消息链表
        }
        return mergeKLists(nodeList);
    }
    
    void follow(int followerId, int followeeId) {
        followList[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followList[followerId].erase(followeeId);
    }

private:
    struct ListNode {
        int tweetId;
        int ts;
        ListNode *next;
        // 保护头节点构造函数
        ListNode() : tweetId(-1), next(nullptr) {}
        // 插入链表构造函数
        ListNode(int tweetId, ListNode *next) : tweetId(tweetId), next(next) {}
    };

    class MyComparator {
    public:
        bool operator()(ListNode *lhs, ListNode *rhs) {
            return lhs->ts < rhs->ts;
        }
    };

    // 需要维护一个用户关注的人的列表，需要频繁查询，增加，删除，不需要有序
    unordered_map<int, unordered_set<int>> followList;

    // 需要维护一个用户已发推文的列表，只需要按顺序添加，不需要删除，修改，需要按顺序查询
    unordered_map<int, ListNode *> tweetList;
    
    int time;

    // 不需要将链表实际合并，链表只读
    vector<int> mergeKLists(vector<ListNode*>& lists) {
        // 需要返回最近的最多十条推文，相当于合并有序链表，用堆实现，需要大顶堆（ts越大时间越靠前）
        priority_queue<ListNode *, vector<ListNode *>, MyComparator> pq; 
        vector<int> ans;
        for (ListNode *node : lists) {
            if (node != nullptr)
                pq.push(node);
        }
        
        while (!pq.empty() && ans.size() < 10) {
            ListNode *next = pq.top();
            pq.pop();
            ans.push_back(next->tweetId);
            if (next->next != nullptr)
                pq.push(next->next);
        }

        return ans;
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */