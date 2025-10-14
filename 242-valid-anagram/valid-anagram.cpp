class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> freq;
        if(s.size() != t.size()) return false;
        for(auto ch: s) {
            freq[ch]++;
        }

        for(auto ch: t) {
            if(freq[ch] == 0) {
                return false;
            } else {
                freq[ch]--;
            }
        }

        return true;
    }
};