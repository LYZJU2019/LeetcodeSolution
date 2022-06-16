class Solution {
public:
    // 首先一颗有向树不能有入度为2的顶点
    // 如果没有入度为2的顶点，则一定存在有向环
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        // 统计顶点数和边的入度
        int N = 0; 
        unordered_map<int, int> inDeg;
        for (vector<int> &edge : edges) {
            int x = edge[0];
            int y = edge[1];
            N = max(N, max(x, y)); 
            inDeg[y]++;
        }
        this->N = N;
        this->inDeg = inDeg;

        // 建立出边数组
        vector<unordered_set<int>> to(N + 1);
        for (vector<int> &edge : edges) {
            int x = edge[0];
            int y = edge[1];
            to[x].insert(y);
        }
        this->to = to;

        // 判断是否存在入度为2的顶点
        vector<vector<int>> candi;  
        for (vector<int> &edge : edges) {
            if (inDeg[edge[1]] == 2) candi.push_back(edge);
        }

        // 存在入度为2的顶点，冗余边一定是二者之一
        if (!candi.empty()) {
            if (!hasCycleAfterRemoveEdge(candi[1])) return candi[1];   // 需要返回edges数组中最后出现的边
            return candi[0];
        }

        // 不存在入度为2的顶点，则一定存在有向环，从右向左依次删除，直到没有有向环
        for (int i = edges.size() - 1; i >= 0; i--) {
            if (!hasCycleAfterRemoveEdge(edges[i])) return edges[i];
        }

        // 不可能运行到此处
        return {};
    }

    // 拓扑排序判断有无有向环
    bool hasCycleAfterRemoveEdge(vector<int> &deleteEdge) {
        queue<int> q;
        // 处理删除的边
        inDeg[deleteEdge[1]]--;
        to[deleteEdge[0]].erase(deleteEdge[1]);

        // 首先把入度为0的边放进queue，如果没有，直接返回true (一定有环)
        for (int i = 1; i <= N; i++) {
            if (inDeg[i] == 0) q.push(i);
        }
        if (q.empty()) return true;
        
        vector<int> topo;
        while (!q.empty()) {
            int next = q.front();
            q.pop();
            topo.push_back(next);
            for (int x : to[next]) {
                inDeg[x]--;
                if (inDeg[x] == 0) {
                    q.push(x);
                }
            }
        }

        // 恢复
        inDeg[deleteEdge[1]]++;
        to[deleteEdge[0]].insert(deleteEdge[1]);

        // size不等于N表示有环
        return topo.size() != N;
    }

private:
    int N;
    vector<unordered_set<int>> to;
    unordered_map<int, int> inDeg;
};