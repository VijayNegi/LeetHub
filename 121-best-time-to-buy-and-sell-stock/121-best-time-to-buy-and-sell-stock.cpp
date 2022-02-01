class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mProfit = 0;
        int currProfit = 0;
        
        for(int i=1;i<prices.size();++i)
        {
            currProfit = max(0, currProfit += prices[i] - prices[i-1] );
            mProfit = max(mProfit,currProfit);
        }
        return mProfit;
    }
};