class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int total = 0, zero_count = 0, one_count = 0;
        int i = 0,j = 0;

        while(j < s.length()) {
            
            if(s[j] == '1') 
                one_count++;
            else
                zero_count++;
             
            
            while(one_count > k && zero_count > k) {
                if(s[i] == '1') {
                    one_count--;
                } else {
                    zero_count--;
                }
                i++;
            }

            total += (j-i+1);
            j++;
        }
        return total;
    }
};