class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> to(numCourses, vector<int>());
        vector<int> inDeg(numCourses, 0);
        for (vector<int> &pre : prerequisites) {
            int x = pre[0];
            int y = pre[1];
            to[y].push_back(x);
            inDeg[x]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (inDeg[i] == 0) q.push(i);
        }

        vector<int> topo;
        while (!q.empty()) {
            int next = q.front();
            q.pop();
            topo.push_back(next);
            for (int y: to[next]) {
                inDeg[y]--;
                if (inDeg[y] == 0) q.push(y);
            }
        }
        
        if (topo.size() != numCourses) return {};
        return topo;
    }
};