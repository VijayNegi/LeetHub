class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        int n= low;
        int dl = 0;
        while(n)
        {
            ++dl;
            n/=10;
        }
        n=high;
        int dh = 0;
        while(n)
        {
            ++dh;
            n/=10;
        }
        vector<int> res;
        for(int i=dl;i<=dh;++i)
        {
            for(int j=1;j<=10-i;++j)
            {
                int num=0;
                for(int k=j;k<j+i;++k)
                    num = num*10 + k;
                if(num<low)
                    continue;
                if(num>high)
                    break;
                res.push_back(num);
            }
        }
        return res;
    }
};