class Solution {
public:
    int minDifficulty(vector<int>& jd, int d) {
        int n = jd.size();
        if(n<d) return -1;
        if(n==d) 
            return accumulate(begin(jd),end(jd),0);
        vector<vector<int>> dp(d+1,vector(n,INT_MAX));
        // fill for 1 day case 
        // dp[x][y]   x - days , y- from this index
        dp[1][n-1] = jd[n-1];
        for(int i=n-2;i>=0;--i) {
            dp[1][i] = max(jd[i],dp[1][i+1]);
        }
        
        for(int k=2;k<=d;++k) {
            //cout<<"day-"<<k<<endl<<endl;
            int currmax = 0;
            for(int i=0;i<(n-k+1);++i) {
                currmax = jd[i];
                //cout<<"start-"<<i<<" value- "<<currmax<<endl;
                for(int j=i+1;j<(n-k+2);++j) {
                    dp[k][i] = min(dp[k][i], currmax+ dp[k-1][j]);
                    //cout<<"partition "<<j<<" -- "<<currmax+ dp[k-1][j]<< "      "; 
                    currmax = max(currmax,jd[j]);
                }
                //cout<<endl;
            }
        }
        return dp[d][0];
    }
};