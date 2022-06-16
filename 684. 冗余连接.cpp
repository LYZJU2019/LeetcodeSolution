class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = 0;
        for (vector<int> &edge : edges) {
            int x = edge[0];
            int y = edge[1];
            n = max(n, max(x, y));
        }
        this->n = n;

        // 建立出边数组，index从1开始
        visited = vector<bool>(n+1, false); 
        to = vector<vector<int>>(n+1, vector<int>());
        for (vector<int> &edge : edges) {
            int x = edge[0];
            int y = edge[1];
            // 建立一条由x指向y的边和一条由y指向x的边
            to[x].push_back(y);
            to[y].push_back(x);

            if (dfs(x, 0)) {
                return {x, y};
            }
        }
        return {};
    }

    bool dfs(int start, int fa) {
        visited[start] = true;
        for (int y : to[start]) {
            if (y == fa) continue;
            if (!visited[y]) dfs(y, start);
            else return true;
        }
        visited[start] = false;
        return false;
    }

private:
    vector<vector<int>> to;
    int n;
    vector<bool> visited;
};