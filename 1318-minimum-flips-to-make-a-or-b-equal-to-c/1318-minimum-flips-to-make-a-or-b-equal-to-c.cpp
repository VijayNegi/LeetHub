class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ab = a | b;
        int result=0;
        for(int i = 0; i<31;++i){
            int t1= c & 1<<i;
            if((ab & 1<<i) == t1)
                continue;
            if(t1)
                ++result;
            else{
                if((a & 1<<i) != t1)
                    ++result;
                if((b & 1<<i ) != t1)
                    ++result;
            }
        }
        return result;
    }
};