class Solution {
public:
    int minDistance(string word1, string word2) {
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
                result = max(result,dp[i][j]);
                //cout<< dp[i][j]<<" ";
            }
            //cout<<endl;
        }
        //cout<<result<<endl;
        return n1-result+ n2-result;
    }
};