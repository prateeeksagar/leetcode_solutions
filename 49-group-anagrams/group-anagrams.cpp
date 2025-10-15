class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        unordered_map<string, vector<string>> mpp;
        vector<vector<string>> result;

        for(auto &s: strs) {

            int freq[26] = {0};            
            for(auto &ch: s) {
                freq[ch - 'a']++;
            }

            string temp = "";
            for(int i = 0; i < 26; i++) {
                if(freq[i] > 0) {
                temp += string(freq[i], i + 'a');
                }
            }

            mpp[temp].push_back(s);
        }

        for(auto &it: mpp) {
            result.push_back(it.second);
        }

        return result;
    }
};