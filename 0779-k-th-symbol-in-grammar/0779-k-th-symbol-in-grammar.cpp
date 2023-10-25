class Solution {
public:
    int kthGrammar(int n, int k) {
        int len = pow(2,n-1);
        bool nan = false;
        while(n!=1){
            if(k>len/2){
                k -= len/2;
                nan = !nan;
            }
            else{
                len/=2;
                --n;
            }
        }
        return nan;
    }
};
/*
0 -> 01
1 -> 10

0
01
0110
01101001
01101001 10010110
*/