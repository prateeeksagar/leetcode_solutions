class Solution {
public:
    bool isVowel(char ch) {
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E'
        || ch == 'I' || ch == 'O' || ch == 'U');
    }
    string reverseVowels(string s) {
        int n = s.length();
        int i = 0;
        int j = n-1;
        while(i < j) {
            if( isVowel(s[i]) && isVowel(s[j]) ) {
                char temp = s[j];
                s[j] = s[i];
                s[i] = temp;
                i++;
                j--; 
            } else if(isVowel(s[i])) {
                j--;
            } else if(isVowel(s[j])) {
                i++;
            } else {
                i++;
                j--;
            }
        }
        return s;
    }
};