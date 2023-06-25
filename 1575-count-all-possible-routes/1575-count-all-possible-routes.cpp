const int mod = 1e9+7;
class Solution {
public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int n = locations.size();
        vector<vector<int>> dp(n,vector(fuel+1,-1));
        function<int (int,int)> dfs = [&](int k,int f){
            //if(f<0) return 0;
            if(dp[k][f]!=-1) return dp[k][f];
            int req = abs(locations[k]-locations[finish]);
            if(req>f) return dp[k][f] = 0;
            int res = 0;
            if(k==finish) ++res;
            for(int i=0;i<n;++i){
                if(i==k) continue;
                int req = abs(locations[k]-locations[i]);
                if(f>=req)
                    res += dfs(i,f-req);
                res %= mod;
            }
            return dp[k][f] = res;
        };
        return dfs(start,fuel);
    }
};