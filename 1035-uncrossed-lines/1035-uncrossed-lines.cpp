class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(),n2=nums2.size();
        vector<vector<int>> dp(n1,vector(n2,-1));
        function<int(int,int)> solve = [&](int i,int j){
            if(i<0 || j<0) return 0;
            if(dp[i][j] != -1) return dp[i][j];
            if(nums1[i]==nums2[j])
                dp[i][j] = 1+solve(i-1,j-1);
            else{
                dp[i][j] = max(solve(i-1,j),solve(i,j-1));
            }
            return dp[i][j];
        };
        return solve(n1-1,n2-1);
        
    }
};