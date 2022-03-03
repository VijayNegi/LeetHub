class Solution {
    vector<vector<int>> dp;
public:
    int numDupDigitsAtMostN(int n) {
        dp = vector(10,vector(1024,-1));
        int last = 0;
        string s = to_string(n);
        int len = s.size();
        bool flag = false;
        int result=0;
        bool valid=false;
        for(int i=0;i<len;++i)
        {
            int limit = s[i]-'0';
            //cout<<i<<" "<<result<<endl;
            for(int j=0;j<limit;++j)
            {
                int tvalid = valid || j>0;
                if((tvalid && (last & (1<<j))) || flag)
                {
                    int dLeft = s.size()-i -1;
                    result += pow(10,dLeft);
                    //cout<<"yeah"<<endl;
                }
                else
                {
                    int mask = last | (1<<j);
                    if(!tvalid)
                        mask = 0;
                    result+=digit_dp(s,i+1,mask,tvalid);
                }
            }
            if(last & (1<<limit))
            {
                flag = true;
            }
            valid = true;
            last = last | (1<<limit);
        }
        return result+flag;
    }
    int digit_dp(string s,int pos,int last,bool valid)
    {
        if(pos==s.size())
            return 0;
        if(dp[pos][last]!=-1)
            return dp[pos][last];
        int sum=0;
        for(int i=0;i<10;++i)
        {
            //int s = 0;
            int tvalid = valid || i>0;
            if(tvalid && ( last & 1<<i))
            {
                int dLeft = s.size()-pos -1;
                sum += pow(10,dLeft);
                //cout<<i<<endl;
            }
            else
            {
                int mask = last | (1<<i);
                if(!tvalid)
                        mask = 0;
                sum+=digit_dp(s,pos+1,mask,tvalid);
            }
        }
        return dp[pos][last] = sum;
    }
};