class Solution {
    vector<int> mem;
public:
    Solution():mem(31,0) {
        
    }
    int fib(int n) {
        if(n<2)
            return n;
        if(mem[n]!=0)
            return mem[n];
        return mem[n] = fib(n-1)+fib(n-2);
    }
};