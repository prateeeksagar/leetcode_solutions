class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string mergedString = "";
        int i = 0;
        while(i < word1.length() || i < word2.length()) {
            if(i < word1.length()) {
                mergedString.push_back(word1[i]);
            }
            if(i < word2.length()) {
                mergedString.push_back(word2[i]);
            }
            i++;
        }
        return mergedString;
     }
};