class Solution {
public:
    int totalMoney(int n) {
        int res=0;
        int week=4;
        while(n){
            if(n>=7){
                n-=7;
                res += week*7;
                ++week;
            }
            else{
                --n;
                res += week -3;
                ++week;
            }
        }
        return res;
    }
};