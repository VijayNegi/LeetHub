class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int l = strs.size();
        vector<pair<int,int>> c;
        for(auto& s:strs )
        {
            int ones = 0;
            int zeros = 0;
            for(auto c:s)
                (c=='0')?++zeros:++ones;
            c.push_back({zeros,ones});
        }
        vector<vector<vector<int>>> dp(l,vector(m+1,vector(n+1,-1)));
        
        function<int(int,int,int)> dfs = [&](int i,int m1,int n1) {
            if(i>=l)
                return 0;
            if(dp[i][m1][n1]!= -1)
                return dp[i][m1][n1];
            
            if(m1 >= c[i].first && n1 >= c[i].second)
                dp[i][m1][n1] = dfs(i+1,m1-c[i].first,n1-c[i].second) +1;
            dp[i][m1][n1] = max(dp[i][m1][n1], dfs(i+1,m1,n1));
            return dp[i][m1][n1];
        };
        return dfs(0,m,n);
    }
};