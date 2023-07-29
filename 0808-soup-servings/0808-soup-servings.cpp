class Solution {
public:
    double soupServings(int n) {
        if(n >5000) return 1;
        int m = ceil((double)n/25);
        vector<vector<double>> dp(m+1,vector<double>(m+1,-1));
        function<double(int,int)> serve = [&](int a,int b)-> double{
            if(a<=0 && b<=0)
                return 0.5;
            
            if(a<=0)  return 1;
            if(b<=0)  return 0;
            if(dp[a][b]!= -1) return dp[a][b];
            double prob = 0;
            prob += 0.25 * serve(a-4,b);
            prob += 0.25 * serve(a-3,b-1);
            prob += 0.25 * serve(a-2,b-2);
            prob += 0.25 * serve(a-1,b-3);
            return dp[a][b] = prob;
        };
        return serve(m,m);
    }
};