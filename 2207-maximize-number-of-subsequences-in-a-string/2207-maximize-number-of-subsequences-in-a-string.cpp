class Solution {
public:
    long long maximumSubsequenceCount(string text, string pattern) {
        int n = text.size();
        vector<int> p2(n+1,0);
        int count=0;
        for(int i=n-1;i>=0;--i)
        {
            if(text[i]==pattern[1])
                ++count;
            p2[i] = count;
        }
        long long result=0;
        count=0;
        for(int i=0;i<n;++i)
        {
            
            if(i<n && text[i]==pattern[0])
            {
                result += p2[i+1];
                ++count;
            }
        }
        return result+max(p2[0],count);   
    }
};