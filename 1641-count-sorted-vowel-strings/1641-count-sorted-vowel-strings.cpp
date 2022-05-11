class Solution {
public:
    int countVowelStrings(int n) {
        int k=5;
        int result=1;
        vector<vector<int>> dp(n+1,vector(k+1,0));
        function<int(int,int)> dfs = [&](int v,int pos){
            if(pos==0)
                return 1;
            if(dp[pos][v]!=0)
                return dp[pos][v];
            int result = 0;
            for(int i=1;i<=v;++i)
                result += dfs(i,pos-1);
            return dp[pos][v] = result;
        };
        result = dfs(k,n);
        return result;
    }
};