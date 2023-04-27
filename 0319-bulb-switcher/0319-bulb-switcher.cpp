class Solution {
public:
    int bulbSwitch(int n) {
        long k=1;
        //int ans=0;
        while(n>=k*k){
            k++;
        }
        return k-1;
    }
};