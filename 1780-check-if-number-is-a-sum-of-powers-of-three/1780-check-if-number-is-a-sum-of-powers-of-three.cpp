class Solution {
public:
    // self :4ms 
    bool checkPowersOfThree1(int n) {
        if(n==1)
            return true;
        int th = 1;
        int maxp = INT_MAX;
        while(n>0) {
            int p=0;
            while(th*3<=n) {
                th*=3;
                ++p;
            }
            if(p==maxp)
                break;
            n -=th;
            maxp=p;
            th=1;
        }
        return n==0; 
    }
    // maths
    
    bool checkPowersOfThree(int n) {
        if(n==1)
            return true;
        if(n%3==2)
            return false;
        return checkPowersOfThree(n/3);
    }
};