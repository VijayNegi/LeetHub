class Solution {
public:
    bool checkPowersOfThree(int n) {
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
            //cout<<"th="<<th<<"\n";
            //cout<<"p="<<p<<"\n";
            n -=th;
            maxp=p;
            th=1;
        }
        //cout<<n;
        return n==0; 
    }
};