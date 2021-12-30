class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if(k%2==0)
            return -1;
        
        int len = 0;
        unsigned long long n = 0;
        unsigned long long limit = 11111111111111; //(long long)1<<60;
        // while(n<k)
        // {
        //     n = n*10+1;
        //     ++len;
        // }
        while(len < 999999 )
        {
           

                n = n*10+1;
                ++len;

                if(n % k == 0)
                    return len;
                // n = n*10+1;
                // ++len;
                 n = n%k;
            
           
            // n = n*10+1;
            // ++len;
        }
        //cout<<len<<endl;
        return -1;
    }   
};