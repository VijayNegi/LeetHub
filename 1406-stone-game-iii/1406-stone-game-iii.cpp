class Solution {
public:
    string stoneGameIII(vector<int>& sv) {
        //int sum = 0;//accumulate(begin(sv),end(sv),0);
       
        int n = sv.size();
        vector<int> sum(n+1,0);
        vector<int> dp(n+1,INT_MIN);
        dp[n]=0;
        for(int i=n-1;i>=0;--i){
            sum[i] = sv[i] + sum[i+1];
            //if(i+3 >= n) dp[i] = sum[i];
            //else {
                int ss=0;
                for(int j=i;j<min(i+3,n) ;++j){
                    ss += sv[j];
                    //int pre = 
                    dp[i] = max(dp[i],ss+ sum[j+1] - dp[j+1]);
                    //cout<<j<<dp[i]<<" "<<ss<<endl;
                }
            //}
            //cout<<dp[i]<<" ";
        }
        //cout<<"\n"<<sum[0]<<" "<<dp[0]<<endl;
        if(sum[0] == 2*dp[0]) return "Tie";
        return sum[0] > 2*dp[0] ? "Bob":"Alice";
    }
};