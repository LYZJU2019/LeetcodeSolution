class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        // frequently check whether there's an obstacle in the position (x, y)
        // need a hashmap
        unordered_set<long long> set;
        for (const vector<int> &obstacle : obstacles)
            set.insert(VecToInt(obstacle));
        
        int dir = 0;        // N: 0, E: 1, S: 2, W: 3
        int x = 0, y = 0;   // current position
        const int dx[4] = {0, 1, 0, -1};
        const int dy[4] = {1, 0, -1, 0};
        int ans = 0;

        for (int command : commands) {
            if (command == -1) {  // turn right
                dir = (dir + 1) % 4;
            } else if (command == -2) {
                dir = (dir + 3) % 4;
            } else {
                for (int i = 0; i < command; i++) {
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];
                    // if robot hits the obstacle, we are done!
                    if (set.find(VecToInt({nx, ny})) != set.end()) break;
                    x = nx;
                    y = ny;
                }
                ans = max(ans, x * x + y * y);
            }
        }

        return ans;
    }

    // vector is not hashable, we have to convert vector / pair to string (slow) / int (fast)
    long long VecToInt(const vector<int> &vec) {
        return (vec[0] + 30000) * 60001ll + (vec[1] + 30000);
    }
};