class Solution {
public:
    // *************************************************
    // *******************递归实现***********************
    // *************************************************
    string reverseWords(string s) {
        if (s.find(" ") == string::npos) {
            return s;
        }
        auto res = reverseWords(s.substr(s.find(" ") + 1));
        res.append(" ");
        res.append(s.substr(0, s.find(" ")));
        int first_place = res.find_first_not_of(" ");
        int last_place = res.find_last_not_of(" ");
        if (first_place != string::npos)
            res = res.substr(first_place);
        if (last_place != string::npos)
            res = res.substr(0, last_place+1);
        return res;
    }
};