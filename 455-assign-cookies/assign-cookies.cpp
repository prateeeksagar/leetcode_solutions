class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int count = 0, j = 0;
        for(int i = 0; i < s.size(); i++) {
            if(j == g.size()) break; // break length of children array should be less than euqual to cookie array
            if(g[j] <= s[i]) {
                count++;
                j++;
            }
        }

        return count;
    }
};