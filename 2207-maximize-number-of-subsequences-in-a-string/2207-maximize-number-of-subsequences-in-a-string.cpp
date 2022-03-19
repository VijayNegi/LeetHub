class Solution {
public:
    long long maximumSubsequenceCount(string text, string pattern) {
        int n = text.size();
        //vector<int> p1(n+1,0);
        vector<int> p2(n+1,0);
        int count=0;
        // for(int i=0;i<n;++i)
        // {
        //     if(text[i]==pattern[0])
        //         ++count;
        //     p1[i]= count;
        // }
        //count =0;
        for(int i=n-1;i>=0;--i)
        {
            if(text[i]==pattern[1])
                ++count;
            p2[i] = count;
        }
        long long result=0;
        count=0;
        long long maxInc=0;
        for(int i=0;i<n;++i)
        {
            //long long p11 = i==0?0:p1[i-1];
            //long long p22 = i==n? 0:p2[i];
            if(i<n && text[i]==pattern[0])
            {
                result += p2[i+1];
                ++count;
            }
                
            //maxInc = max(count,maxInc);
            //maxInc = max(p11,maxInc);
        }
        maxInc = max(p2[0],count);
        
         return result+maxInc;   
    }
};