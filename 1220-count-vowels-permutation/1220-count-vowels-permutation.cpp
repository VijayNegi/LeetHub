const int mod = 1e9+7;
class Solution {
public:
    int countVowelPermutation(int n) {
        map<char,vector<char>> pre;
        pre['a'] = {'e','i','u'};
        pre['e'] = {'a','i'};
        pre['i'] = {'e','o'};
        pre['o'] = {'i'};
        pre['u'] = {'i','o'};
        
        vector<vector<int>> dp(n+1,vector(256,0));
        for(auto& c: pre) {
            dp[1][c.first] = 1;
        }
        //dp[1]['a'] = dp[1]['a'] = dp[1]['a'] = dp[1]['a'] = dp[1]['a']
        
        for(int i=1;i<n;++i) {
            for(auto& c: pre) {
                int ch = c.first;
                for(auto& k: c.second) {
                    dp[i+1][k] =  ((long)dp[i+1][k] + dp[i][ch])%mod;
                    
                }
                
            }
        }
        long result = 0;
        for(auto& c: pre) {
            result += dp[n][c.first];
            result %= mod;
        }
        return result;
    }
};
