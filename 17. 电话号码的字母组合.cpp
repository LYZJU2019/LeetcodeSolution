class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.length() == 0) return ans;
        this->digits = digits;
        string prev = "";
        dfs(prev, 0, digits.length());
        return ans;
    }

    void dfs(string &prev, int begin, int n) {
        if (prev.length() == n) {
            ans.push_back(prev);
            return;
        }

        for (int i = 0; i < str[digits[begin] - '0'].length(); i++) {
            prev.push_back(str[digits[begin] - '0'][i]);
            dfs(prev, begin + 1, n);
            prev.pop_back();
        }
    }

private:
    vector<string> str {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> ans;
    string digits;
};