class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // for(int i = 0; i < nums.size(); i++) {
        //     for(int j = i+1; j < nums.size(); j++) {
        //         if(nums[i] == nums[j]) return true;
        //     }
        // }
        // return false;

        unordered_map<int, int> freq;
        for(int i = 0 ; i < nums.size(); i++) {
            freq[nums[i]]++;
            if(freq[nums[i]] > 1) {
                return true;
            }
        }
        return false;
    }
};