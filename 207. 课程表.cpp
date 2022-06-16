class Solution {
public:
    // 基于BFS的拓扑排序
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) { 
        // 建立Graph
        vector<vector<int>> to(numCourses, vector<int>());
        vector<int> inDeg(numCourses, 0);
        for (vector<int> &pre: prerequisites) {
            int x = pre[0];
            int y = pre[1];
            // 建立一条由y指向x的有向边
            to[y].push_back(x);
            inDeg[x]++;
        }

        // 找到入度为0的点放进queue
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (inDeg[i] == 0) q.push(i);
        }

        vector<int> topo;
        while (!q.empty()) {
            int next = q.front();
            q.pop();
            topo.push_back(next);
            // 不断扩展队列中的点，周围点的入度减一
            for (int y: to[next]) {
                inDeg[y]--;
                // 只有当入度为0时才入队
                if (inDeg[y] == 0) q.push(y);
            }
        }

        return topo.size() == numCourses; 
    }

};