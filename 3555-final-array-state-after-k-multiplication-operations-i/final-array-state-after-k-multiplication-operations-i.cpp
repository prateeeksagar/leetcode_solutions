class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        
        while(k--) {
            cout << k;
            int min = nums[0],min_idx=0;
            
            for(int i = 0 ; i < nums.size(); i++) {
                if(nums[i] < min) {
                    min = nums[i];
                    min_idx = i;
                }
            }
            nums[min_idx] = nums[min_idx] * multiplier;
        }

        return nums;
    }
};