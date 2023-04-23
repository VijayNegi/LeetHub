const int mod = 1e9+7;
class Solution {
public:
    int numberOfArrays(string s, int k) {
        int n = s.size();
        vector<int> dp(n,-1);
        function<int(int)> ways = [&](int pos){
            if(pos==n) return 1;
            if(dp[pos] != -1) return dp[pos];
            if(s[pos] == '0') return dp[pos] = 0;
            long num = 0;
            int p = pos;
            int count = 0;
            while(p < n){
                num = num*10 + s[p++]-'0';
                if(num >k) break;
                count += ways(p);
                count %=mod;
            }
            return dp[pos] = count;
        };
        return ways(0);
    }
};