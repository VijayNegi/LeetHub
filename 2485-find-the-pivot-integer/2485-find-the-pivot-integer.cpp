class Solution {
public:
    int pivotInteger(int n) {
        int sum = n*(n+1)/2;
        int prev = 0;
        for(int i=1;i<=n;++i){
            sum -=i;
            if(sum == prev) return i;
            prev += i;
        }
        return -1;
    }
};