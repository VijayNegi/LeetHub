class Solution {
public:
    // Floyd Warshall
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        int n = values.size();
        
        unordered_map<string,int> strid;
        int idx = 0;
        for(int i=0;i<n;++i)
        {
            string s1 = equations[i][0];
            string s2 = equations[i][1];
            if(strid.count(s1)==0)
                strid[s1] = idx++;
            if(strid.count(s2)==0)
                strid[s2] = idx++;
        }
        
         vector<vector<double>> dp(idx, vector(idx,-1.0));
        for(int i=0;i<n;++i)
        {
            string s1 = equations[i][0];
            string s2 = equations[i][1];
             // fill dp
            dp[ strid[s1] ][ strid[s2] ] = values[i];
            dp[ strid[s2] ][ strid[s1] ] = 1/values[i];
         }
        
        for(int k=0;k<idx;++k)
            for(int i=0;i<idx;++i)
                for(int j=0;j<idx;++j)
                {
                    if(dp[i][k] <0 || dp[k][j] <0 || dp[i][j]>=0)
                        continue;
                    dp[i][j] = dp[i][k] * dp[k][j];
                    dp[j][i] = 1/dp[i][j];
                }
        
        vector<double> result;
        for(auto q:queries)
        {
            string s1 = q[0];
            string s2 = q[1];
            
            if(strid.count(s1) ==0 || strid.count(s2)==0)
            {
                result.push_back(-1);
                continue;
            }
            result.push_back( dp[ strid[s1] ][ strid[s2] ]);
        }
        
        return result;
        
        
    }
};