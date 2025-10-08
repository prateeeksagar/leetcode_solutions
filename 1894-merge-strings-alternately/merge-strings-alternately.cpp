class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string mergedString = "";
        int n1 = word1.length();
        int n2 = word2.length();

        mergedString.reserve(n1 + n2);

        int min_len = min(n1, n2);

        for(int i = 0; i < min_len; i++) {
            mergedString.push_back(word1[i]);
            mergedString.push_back(word2[i]);
        }

        if(n1 > n2) {
            mergedString.append(word1, min_len, n1-min_len);
        } else if(n2 > n1) {
            mergedString.append(word2, min_len, n2 - min_len);
        }
        return mergedString;
     }
};