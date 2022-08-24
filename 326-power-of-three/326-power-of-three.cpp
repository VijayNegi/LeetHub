class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<=0)
            return false;
        long k=1;
        while(k>0 && k<=n) {
            if(k==n)
                return true;
            k *=3;
        }
        return false;
    }
};
