class Solution {
public:
    int minimumWhiteTiles1(string floor, int nC, int cLen) {
        int n = floor.size();
        if(nC*cLen>=n)
            return 0;
        
        vector<int> sw(n-cLen+1,0);
        int count=0;
        int white=0;
        for(int i=0;i<n;++i)
        {
            if(floor[i]=='1')
                ++count,++white;
            if(i==cLen-1)
                sw[i-cLen+1] = count;
            if(i>=cLen)
            {
                if(floor[i-cLen]=='1')
                    --count;
                sw[i-cLen+1] = count;
            }
        }
        int result = white;
        vector<vector<int>> dp(n+1,vector(nC+1,-1));
        function<int(int,int)> bt1 = [&](int pos,int remain)
        {
            if(pos>=n || remain==0)
                return 0 ;
             
             if(dp[pos][remain]!=-1)
                 return dp[pos][remain];
            int covered = max(sw[pos-cLen+1]+bt1(pos+cLen,remain-1), bt1(pos+1,remain));
            return dp[pos][remain] = covered;
        };

        int cov = bt1(cLen-1,nC);
        return white-cov;
    };
    // DP bottom up: 
    int minimumWhiteTiles(string s, int nc, int l) {
        int n = s.size();
        vector<vector<int>> dp(n + 1, vector<int>(nc + 1));
        for (int i = 1; i <= n; ++i) {
            for (int k = 0; k <= nc; ++k) {
                int jump = dp[i - 1][k] + s[i - 1] - '0';
                int cover = k > 0 ? dp[max(i - l, 0)][k - 1] : 1000;
                dp[i][k] = min(cover, jump);
            }
        }
        return dp[n][nc];
    }

};