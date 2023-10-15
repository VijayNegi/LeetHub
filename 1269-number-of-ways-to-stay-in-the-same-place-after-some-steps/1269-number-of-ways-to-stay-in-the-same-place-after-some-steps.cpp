const int mod = 1e9+7;
class Solution {
public:
    // TLE
    int numWays(int steps, int arrLen) {
        int arr = min(steps,arrLen);
        vector<int> dp0(arrLen,0);
        vector<int> dp1(arrLen,0);
        dp0[0] = 1;
        for(int i=0;i<steps;++i){
            for(int j=0;j<arr;++j){
                long val = dp0[j];
                if(j>0)
                    val += dp0[j-1];
                if(j<arr-1)
                    val += dp0[j+1];
                dp1[j] = val% mod;
            }
            swap(dp0,dp1);
        }
        return dp0[0];
    }
};