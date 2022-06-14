class Solution {
public:
    // DP: try to maintain a table of number of character that are matched till now
    // self : 61ms
    int minDistance1(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        vector<vector<int>> dp(n1,vector(n2,0));
        int result=0;
        for(int i=0;i<n1;++i) {
            for(int j=0;j<n2;++j) {
                if(word1[i]==word2[j])
                    ++dp[i][j];
                if(i>0 && j>0)
                    dp[i][j] += dp[i-1][j-1];
                if(j>0)
                    dp[i][j] = max(dp[i][j],dp[i][j-1]);
                if(i>0)
                    dp[i][j] = max(dp[i][j],dp[i-1][j]);
                //result = max(result,dp[i][j]);
            }
        }
        return n1+ n2- 2* dp[n1-1][n2-1];
    }
    // same as above
    int minDistance(string s1, string s2) {
         int n1 = s1.size();
        int n2 = s2.size();
        vector<vector<int>> dp(n1+1,vector(n2+1,0));
        for (int i = 0; i <= n1; i++) {
            for (int j = 0; j <= n2; j++) {
                if (i == 0 || j == 0)
                    continue;
                if (s1[i - 1] == s2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return n1 + n2 - 2 * dp[n1][n2];
    }
};