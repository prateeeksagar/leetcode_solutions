class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        unordered_map<string, vector<string>> mpp;
        vector<vector<string>> result;

        for(auto &s: strs) {
            string temp = s;
            sort(temp.begin(), temp.end());

            mpp[temp].push_back(s);
        }

        for(auto &it: mpp) {
            result.push_back(it.second);
        }

        return result;
    }
};