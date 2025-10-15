class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int siz = nums.size();
        unordered_map<int, int> mpp;
        for(int i = 0 ; i < siz; i++) {
            mpp[nums[i]] = i;
        }

        for(int i = 0; i < siz; i++) {
            int remainVal =  target - nums[i];
            if((mpp.find(remainVal) != mpp.end()) && mpp[remainVal] != i) {
                return {i, mpp[remainVal]};
            }
        }
        return {-1, -1};
    }
};