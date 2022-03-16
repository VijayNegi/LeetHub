class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.size()+1,vector(p.size()+1,-1));
        return match(s,s.size()-1,p,p.size()-1,dp);
    }
    bool match(string& s,int si, string& p,int pi, vector<vector<int>>& dp)
    {
        //cout<<si<<" "<<pi<<endl;
        if(si==-1 && pi==-1)
            return true;
        if(pi==-1) // pattern could have redundent match so wait like a* at beginning
            return si==-1;
        if(dp[si+1][pi+1]!= -1)
            return dp[si+1][pi+1];
        if(p[pi]=='*')
        {
            if(match(s,si,p,pi-2,dp))
                return dp[si+1][pi+1] = true;
            while(si>=0 && (s[si]==p[pi-1] || p[pi-1]=='.'))
                if(match(s,--si,p,pi-2,dp))
                    return dp[si+1][pi+1] = true;
            return dp[si+1][pi+1] =false;
        }
        else if(si>=0)
        {
            if((s[si]==p[pi] || p[pi]=='.') && match(s,si-1,p,pi-1,dp) )
                return dp[si+1][pi+1] = true;
        }
        return dp[si+1][pi+1] = false;
        
    }
};