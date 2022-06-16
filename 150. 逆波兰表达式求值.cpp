class Solution {
public:
    // 遇到数字，压入栈；遇到符号，取出栈顶两个数计算，压入栈；
    // 栈中唯一的数就是最终答案
    // 题目中只说最终答案在int表示的范围之内，但没有说中间结果在int范围内
    int evalRPN(vector<string>& tokens) {
        stack<long long> s;
        for (string &token : tokens) {
            if (token == "+" || token == "-" || token == "/" || token == "*") {
                long long right = s.top();
                s.pop();
                long long left = s.top();
                s.pop();
                s.push(calc(left, right, token[0]));
            } else {
                s.push(stoi(token));
            }
        }

        return s.top();
    }

    long long calc(long long left, long long right, char op) {
        switch (op) {
            case '+':
                return left + right;
            case '-':
                return left - right;
            case '*':
                return left * right;
            default:
                return left / right;
        }

        return 0; // 不可能执行到这里
    }
};