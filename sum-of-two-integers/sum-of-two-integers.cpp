class Solution {
public:
    int getSum(int a, int b) {
        int min = (abs(a)>abs(b))?b:a;
        int max =  (abs(a)>abs(b))?a:b;
        bool op = min>=0? true:false;
        for(int i=0;i<abs(min);++i)
        {
            if(op)
                ++max;
            else
                --max;
        }
        return max;
            
    }
};