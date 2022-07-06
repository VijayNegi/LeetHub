class Solution {
    vector<int> mem;
public:
    Solution():mem(31,0) {
    }
    // recursion
    int fib1(int n) {
        if(n<2)
            return n;
        if(mem[n]!=0)
            return mem[n];
        return mem[n] = fib(n-1)+fib(n-2);
    }
    // iteration
    int fib(int n) {
        std::vector<int> dp(n+2,-1);
        dp[0]=0;
        dp[1]=1;
        int i=1;
        while(++i<=n) {
            dp[i]=dp[i-2]+dp[i-1];
        }
        return dp[n];
    }
};