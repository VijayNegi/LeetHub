class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result(n+1,0);
        if(n==0)
            return result;
        result[1]=1;
        int k=2,i=2,j=0;
        while(i<=n)
        {
            if(j>=k)
            {
                j=0;
                k*=2;
            }
            result[i++] = result[j++]+1;
        }
        return result;
    }
};
