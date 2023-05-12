class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int result=0;
        int n = questions.size();
        vector<long> dp(n,-1);
        function<long(int)> dfs = [&](int i)-> long {
            if(i>=n) return 0;
            if(dp[i]!=-1) return dp[i];
            dp[i] = max(dfs(i+1+questions[i][1])+ questions[i][0],dfs(i+1) );
            return dp[i];
        };
        return dfs(0);
    }
};