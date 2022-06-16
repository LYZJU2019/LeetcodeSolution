class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for (char ch : s) {
            if (ch == '(' || ch == '[' || ch == '{') 
                stk.push(ch);
            else {
                if (stk.empty()) return false;
                char pair = stk.top(); stk.pop();
                switch (ch) {
                    case ')':
                        if (pair != '(') return false;
                        break;
                    case ']':
                        if (pair != '[') return false;
                        break;
                    default:
                        if (pair != '{') return false;
                        break;
                }
            }
        }
        return stk.empty();
    }
};