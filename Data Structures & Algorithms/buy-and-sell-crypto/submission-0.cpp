class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0;

        int maxprofit = 0;

        for(int r = 0; r < prices.size(); r++){
            int currprofit = prices[r] - prices[l];

            while(l < r && currprofit < 0){
                currprofit += prices[r] - prices[l];
                l++;
            }

            maxprofit = max(maxprofit, currprofit);
        }

        return maxprofit;
    }
};
