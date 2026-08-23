class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0;

        int maxprofit = 0;

        for(int r = 0; r < prices.size(); r++){
            if(prices[r] > prices[l]){
                maxprofit = max(maxprofit, prices[r] - prices[l]);   
            }
            else{
                l = r;
            }
        }

        return maxprofit;
    }
};
