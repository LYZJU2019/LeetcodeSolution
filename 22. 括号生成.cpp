class Solution {
public:
    vector<string> generateParenthesis(int n) {
        // backtracking is not feasible (you have to remember where '(' appears in the path)
        // instead, using divide and conquer
        // (A)B: valid combination must have '(' as the first char, and must have a corresponding 
        // matching ')'
        // A: k-1, B: n-k k from 1 to n
        if (n == 0) 
            return {""};
        
        if (map.find(n) != map.end())
            return map[n];

        vector<string> ans;
        for (int k = 1; k <= n; k++) {
            auto A = generateParenthesis(k-1);
            auto B = generateParenthesis(n-k);
            for (const string &a : A) {
                for (const string &b : B) {
                    ans.push_back("(" + a + ")" + b);
                }
            }
        }
        map[n] = ans;
        return ans;
    }

private:
    unordered_map<int, vector<string>> map;
};