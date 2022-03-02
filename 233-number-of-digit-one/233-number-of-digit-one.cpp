class Solution {
    vector<vector<vector<int>>> dp;
public:
    int countDigitOne(int n) {
        dp = vector(10,vector(82,vector(2,-1)));
        string s = to_string(n);
        return digit_dp(s,0,0,1);
    }
    
    int digit_dp(string s,int pos,int sum,int edge)
    {
        if(pos == s.size())
            return sum;
        if(dp[pos][sum][edge] != -1)
            return dp[pos][sum][edge];
        int limit = 9;
        if(edge==1)
            limit = s[pos]-'0';
        int result = 0;
        for(int i=0;i<=limit;++i)
        {
            int lmt = edge && i==limit;
            if(i==1)
            {
                result += digit_dp(s,pos+1,sum+1, lmt);
            }
            else
                result += digit_dp(s,pos+1,sum, lmt);
        }
        
        return dp[pos][sum][edge] = result;
    }
};