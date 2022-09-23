int mod = 1e9+7;
class Solution {
public:
    int concatenatedBinary(int n) {
        uint64_t sum=0;
        for(int i=1;i<=n;++i) {
            int k=i;
            while(k) {
                sum <<=1;
                k>>=1;
            }
            sum = sum | i;
            sum  = sum % mod;
        }
        return sum;
    }
};