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
        
        //vector<vector<int>> dp(2,vector(256,0));
        vector<int> dp(256,0);
        for(auto& c: pre) {
            dp[c.first] = 1;
        }
        
        for(int i=1;i<n;++i) {
            vector<int> temp(256,0);
            for(auto& c: pre) {
                int ch = c.first;
                for(auto& k: c.second) {
                    temp[k] =  ((long)temp[k] + dp[ch])%mod;
                }
            }
            swap(dp,temp);
        }
        long result = 0;
        for(auto& c: pre) {
            result += dp[c.first];
            result %= mod;
        }
        return result;
    }
};
