class Solution {
public:
    int divide(int dividend, int divisor) {
        long result=0;
        bool sign = false;
        if(dividend<0) sign = !sign;
        if(divisor<0) sign = !sign;
        long dvd = abs(dividend*1.0);
        long dvr = abs(divisor*1.0);
        //cout<<dvd<<" "<<dvr<<endl;
        long d = dvr;
        long count=1;
        while(dvd >= d)
        {
            //cout<<result<<" "<<dvd<<" "<<d<<endl;
            if(dvd >= d)
            {
                dvd -=d;
                result +=count;
                d <<=1;
                count<<=1;
            }
            if(d>dvd)
            {
                 d = dvr;
                count=1;
            }
        }
        result = sign? -1*result:result;
        if(result >INT_MAX) return INT_MAX;
        if(result < INT_MIN) return INT_MIN;
        return result;
    }
};