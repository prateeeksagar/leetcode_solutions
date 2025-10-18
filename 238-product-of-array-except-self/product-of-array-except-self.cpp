class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n,1), right(n,1), result(n);
        
        // prefix
        for(int i = 1; i < n; i++) {
            left[i] = nums[i-1] * left[i-1];
        }

        // suffix
        for(int j = n-2; j >= 0; j--) {
            right[j] = nums[j+1] * right[j+1];
        }

        // combine prefix and postfix
        for(int i = 0; i < n; i++) {
            result[i] = left[i] * right[i];
        }

        return result;
    }
};