class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> isHighest(candies.size(), false);
        int highestCandies = *max_element(candies.begin(), candies.end());

        for(int i = 0; i < candies.size(); i++) {
            if(candies[i] + extraCandies >= highestCandies) {
                isHighest[i] = true;
            }
        }

        return isHighest;
    }
};