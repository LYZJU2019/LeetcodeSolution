class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> map;
        vector<string> ans;
        for (string &cpdomain : cpdomains) {
            int pos =  cpdomain.find(" ");
            int nums = stoi(cpdomain.substr(0, pos));
            auto splitted = SplitString(cpdomain, pos+1);
            for (const string &str : splitted) {
                map[str] += nums;
            }
        }

        for (auto KV_pair : map) {
            string str = to_string(KV_pair.second) + " " + KV_pair.first;
            ans.push_back(str);
        }

        return ans;
    }

    vector<string> SplitString(const string &str, int start) {
        vector<string> ret;
        for (int pos = str.length() - 1; pos >= start; pos--) {
            if (str[pos] == '.') {
                ret.push_back(str.substr(pos+1));
            }
        }

        ret.push_back(str.substr(start));
        return ret;
    }
};