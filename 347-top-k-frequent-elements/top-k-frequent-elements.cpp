class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        priority_queue<pair<int,int>> pq;
        // storing frequency
        for(int i = 0 ; i < nums.size(); i++) {
            mpp[nums[i]]++;
        }

        for(auto &it: mpp) {
            pq.push({it.second, it.first});
        }

        vector<int> result;
        while(k--) {
            result.push_back(pq.top().second);
            pq.pop();
        }

        return result;
    }
};