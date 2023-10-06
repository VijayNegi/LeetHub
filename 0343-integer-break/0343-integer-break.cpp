class Solution {
public:
    int integerBreak(int n) {
        int result=0;
        vector<int> dp(60,-1);
        function<int(int)> dfs = [&](int num){
            if(num<=2) return 1;
            //if(num==3) return 2;
            if(dp[num]!= -1) return dp[num];
            for(int i=2; i<=(num+1)/2;++i){
                dp[num] = max(i*max(num-i,dfs(num-i)),dp[num]);
            }
            //dp[num] = max(dp[num],num);
            return dp[num];
        };
        return dfs(n);
    }
};