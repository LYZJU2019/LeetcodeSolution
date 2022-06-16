class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int k = 0;
        vector<int> ans;

        for (const string &word : words) {
            words_map[word]++;
        }

        for (const string &str : words) 
            k += str.length();
        
        for (int i = 0; i + k <= s.length(); i++) {
            string substr = s.substr(i, k);
            if (IsValid(substr, words)) ans.push_back(i);
        }

        return ans;
    }

    bool IsValid(string &str, vector<string> &words) {
        unordered_map<string, int> str_map;

        int k = words[0].length();
        for (int i = 0; i + k <= str.length(); i += k) {
            str_map[str.substr(i, k)]++;
        }

        for (auto KV_pair : str_map) {
            if (words_map.find(KV_pair.first) == words_map.end() ||
                words_map[KV_pair.first] != str_map[KV_pair.first]) 
                
            return false;
        }

        return true;
    }

private:
    unordered_map<string, int> words_map;
};