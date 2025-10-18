class Solution {
public:
    bool isAlphanumeric(char ch) {
        return ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'));
    }

    bool isPalindrome(string s) {
        int i = 0, j = s.length()-1;
        
        while(i <= j) {
            if(isAlphanumeric(s[i]) && isAlphanumeric(s[j]) ) {
                char leftChar = tolower(s[i]);
                char rightChar= tolower(s[j]);
                if(leftChar != rightChar) {
                    return false;
                }
                i++;
                j--;
            } else if(isAlphanumeric(s[i])) {
                j--;
            } else {
                i++;
            }
        }

        return true;
    }
};