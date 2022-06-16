class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        to = vector<vector<int>>(numCourses, vector<int>());
        reachable = vector<unordered_set<int>>(numCourses, unordered_set<int>());
        visited = vector<bool>(numCourses, false);
        vector<bool> ans;
        vector<int> inDeg(numCourses, 0);
        for (vector<int> &pre: prerequisites) {
            int x = pre[0];
            int y = pre[1];
            to[x].push_back(y);
            inDeg[y]++;
        }
        
        for (int i = 0; i < numCourses; i++) {
            if (inDeg[i] == 0)
                compute(i);
        }

        for (vector<int> &query: queries) {
            int x = query[0];
            int y = query[1];
            ans.push_back(reachable[x].find(y) != reachable[y].end());
        }

        return ans;
    }

    // 哪些课程以i为先修课
    void compute(int i) {
        reachable[i].insert(i);
        for (int y: to[i]) {
            if (!visited[y]) {
                visited[y] = true;
                compute(y);
            }
            reachable[i].insert(reachable[y].begin(), reachable[y].end());
        }
    }
private:
    vector<unordered_set<int>> reachable;
    vector<vector<int>> to;
    vector<bool> visited;
};