class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int min_price = prices[0];
        for(int i = 0 ; i < prices.size(); i++) {
            if(prices[i] < min_price) {
                min_price = prices[i];
            } else {
                int current_price = prices[i] - min_price;
                profit = max(profit, current_price);
            }
        }

        return profit;
    }
};