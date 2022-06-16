class Solution {
public:
    /**
     * root: k
     * left: [1, k-1] (k-1) right: [k+1, n] (n-k)  k from 1 to n
     */
    int numTrees(int n) {
        if (n == 0) return 1;
        if (map.find(n) != map.end()) return map[n];

        int ans = 0;
        for (int k = 1; k <= n; k++) {
            ans += numTrees(k-1) * numTrees(n-k);
        }
        map[n] = ans;
        return ans;
    }

private:
    unordered_map<int, int> map;
};