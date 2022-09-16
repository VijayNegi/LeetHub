class Solution {
public:
    // dp: self :TLE
    int maximumScore1(vector<int>& nums, vector<int>& multipliers) {
        int n = nums.size();
        int m = multipliers.size();
        vector<vector<vector<int>>> memo(m,vector(n,vector(n,-1)));
        dp(memo,0,n-1,0,nums,multipliers);
        return memo[0][0][n-1];
    }
    int dp(vector<vector<vector<int>>>& memo, int l,int r, int i,vector<int>& nums,vector<int>& mul) {
        if(i>=mul.size())
            return 0;
        if(memo[i][l][r] != -1)
            return memo[i][l][r];
        memo[i][l][r] = mul[i]*nums[l] + dp(memo,l+1,r,i+1,nums,mul);
        memo[i][l][r] = max(memo[i][l][r] , mul[i]*nums[r] + dp(memo,l,r-1,i+1,nums,mul));
        return memo[i][l][r];
    }
    // DP space optimized : TLE
    int maximumScore2(vector<int>& nums, vector<int>& mults) {
        int memo[1001][1001] = {};
        function<int(int,int)> dfs = [&](int l, int i) {
            if (i >= mults.size())
                return 0;
            if (!memo[l][i]) {
                int r = nums.size() - 1 - (i - l);
                memo[l][i] = max(nums[l] * mults[i] + dfs(l + 1, i + 1), 
                    nums[r] * mults[i] + dfs(l, i + 1));
            }
            return memo[l][i];
        };
        return dfs(0, 0);
    }
    
    // DP bottom up
    int maximumScore(vector<int>& v, vector<int>& m) {
        
        vector<vector<int>> dp(m.size()+1, vector<int>(m.size()+1));
        for(int i = 0; i < dp.size(); i++){
            dp[i][dp[0].size()-1] = 0;
            dp.back()[i] = 0;
        }
        for(int i = dp.size()-2; i >= 0; i--) {
            for(int j = dp[0].size()-2; j >=0; j--) {
                dp[i][j] = max(m[i]*v[j] + dp[i+1][j+1],
                                    m[i]*v[v.size()-1-(abs(i-j))] + dp[i+1][j]);
            }
        }
        return dp[0][0];
    }
};


