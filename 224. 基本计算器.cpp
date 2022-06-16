class Solution {
public:

    int calculate(string str) {
        str.push_back(' ');  // 保证读到str末尾的数字
        string num = "";
        vector<string> tokens;
        stack<char> s;
        bool needZero = true;  // 一开始的时候必须初始化为true，比如-2+1

        for (char ch : str) {
            if (ch >= '0' && ch <= '9') {
                num += ch;
                needZero = false;
                continue;
            }
            if (!num.empty()) {
                tokens.push_back(num);
                num = "";
                needZero = false;
            }
            if (ch == ' ') continue;
            if (ch == '(') {
                s.push(ch);
                needZero = true;
                continue;
            }
            // 直接把最近的左括号后面的运算符全部弹出来即可
            if (ch == ')') {
                while (s.top() != '(') {
                    tokens.push_back(string(1, s.top()));  // 防止变成ascii码
                    s.pop();
                }
                s.pop();
                needZero = false;
                continue;
            }

            if ((ch == '+' || ch == '-') && needZero) {
                tokens.push_back("0");
            }

            // 此时ch一定是运算符
            // 这里必须是while，因为要把所有的高级和同级运算符全部弹出来
            while (!s.empty() && getOpRank(s.top()) >= getOpRank(ch)) {
                tokens.push_back(string(1, s.top()));  // 防止变成ascii码
                s.pop();
            }
            s.push(ch);
            needZero = true;
        }

        while (!s.empty()) {
            tokens.push_back(string(1, s.top()));
            s.pop();
        }
        // for (string &s : tokens) cout << s << endl;
        return evalRPN(tokens);
    }

    int getOpRank(char ch) {
        if (ch == '+' || ch == '-') return 1;
        if (ch == '*' || ch == '/') return 2;
        return 0;
    }

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