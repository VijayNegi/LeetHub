class Solution {
public:
    int coinChange1(vector<int>& coins, int amount) {
        sort(coins.begin(),coins.end(),greater<int>());
        int n = coins.size();
        int res=0;
        function<bool(int,int)> makeSum = [&](int cIdx,long remain)
        {
            if(remain==0)
                return true;
            if(cIdx==n)
                return false;
            int count = (remain/coins[cIdx]);
            remain -= count*coins[cIdx];
            while(count>=0)
            {
                if(makeSum(cIdx+1,remain))
                {
                    res += count;
                    return true;
                }
    
                --count;
                remain += coins[cIdx];
            }
            
            return false;
            
        };
        
        if(makeSum(0,amount))
            return res;
        return -1;
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,-1);
        dp[0] = 0;
        for(int i=1;i<=amount;++i)
        {
            for(auto c:coins)
            {
                if(i-c >=0 && dp[i-c] >=0)
                    dp[i] = dp[i]==-1 ?dp[i-c] + 1 : min(dp[i], dp[i-c] + 1);
            }
        }
        return dp[amount];
    }
};