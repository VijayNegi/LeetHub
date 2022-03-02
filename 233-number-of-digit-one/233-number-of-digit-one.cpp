class Solution {
    vector<vector<vector<int>>> dp;
    vector<vector<int>> dp2;
public:
    // digit dp: 26 ms
    int countDigitOne1(int n) {
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
    //digit dp 2 states
     int countDigitOne(int n) {
        dp2 = vector(10,vector(82,-1));
        string s = to_string(n);
         int len = s.size();
         int sum = 0;
         int result = 0;
         for(int i=0;i<len;++i)
         {
             int limit = s[i]-'0';
             for(int j=0;j<limit;++j)
             {
                 int tsum = sum + (j==1);
                 result += digit_dp2(s,i+1,tsum);
             }
             if(limit==1)
                 ++sum;
         }
        return result + sum;
    }
    
    int digit_dp2(string s,int pos,int sum)
    {
        if(pos == s.size())
            return sum;
        if(dp2[pos][sum] != -1)
            return dp2[pos][sum];
        int limit = 9;
        int result = 0;
        for(int i=0;i<=limit;++i)
        {
            
            if(i==1)
            {
                result += digit_dp2(s,pos+1,sum+1);
            }
            else
                result += digit_dp2(s,pos+1,sum);
        }
        return dp2[pos][sum] = result;
    }
};