class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // we need to group words with the same feature together
        // the key is to design the grouping critieria
        unordered_map<string, vector<string>> map;
        vector<vector<string>> ans;
        for (const string& str : strs) {
            string copy = str;
            sort(copy.begin(), copy.end());
            map[copy].push_back(str);
        }

        for (auto KV_pair : map) {
            ans.push_back(KV_pair.second);
        }

        return ans;
    }
};