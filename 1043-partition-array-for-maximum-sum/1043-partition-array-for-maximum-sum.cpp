class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n,-1);
        function<int(int)> dfs = [&](int p){
            if(p>=n) return 0;
            if(dp[p]>=0) return dp[p];
            int m=0;
            for(int i=p;i<n and i<p+k;++i){
                m = max(m,arr[i]);
                dp[p] = max(m*(i-p+1) + dfs(i+1), dp[p]);
            }
            return dp[p];
        };
        return dfs(0);
    }
};