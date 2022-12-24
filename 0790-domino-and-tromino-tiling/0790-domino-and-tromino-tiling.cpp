const int mod = 1e9+7;
class Solution {
public:
    int numTilings(int n) {
        if(n==1) return 1;
        if(n==2) return 2;
        vector<vector<int>> dp(n,vector(2,0));
        dp[0][0]=1;
        dp[1][0]=2;
        dp[1][1]=2;
        for(int i=2;i<n;++i){
            dp[i][0] += dp[i-1][0]+ (dp[i-1][1] + dp[i-2][0])%mod;
            dp[i][1] += ((2*dp[i-2][0])%mod+ dp[i-1][1])%mod;
            dp[i][0] %=mod;
            dp[i][1] %=mod;
        }
        return dp[n-1][0];
    }
};