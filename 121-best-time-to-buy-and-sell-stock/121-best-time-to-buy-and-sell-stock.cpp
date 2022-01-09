class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxp=0;
        int minseen = prices[0];
        
        for(auto p:prices)
        {
            maxp = max(maxp, p - minseen);
            minseen = min(minseen,p);
        }
        return maxp;
    }
};