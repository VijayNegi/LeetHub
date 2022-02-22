class Solution {
public:
    bool validPalindrome(string s) {
        int n = s.size();
        int i=0,j=n-1;
        int k=1;
        while(i<j)
        {
            if(s[i]==s[j])
            {
                ++i;--j;
            }
            else if(k>0)
                ++i,--k;
            else 
                break;
                
        }
        if(i>=j)
            return true;
        i=0,j=n-1,k=1;
        while(i<j)
        {
            if(s[i]==s[j])
            {
                ++i;--j;
            }
           else if(k>0)
                --j,--k;
            else 
                break;
        }
        if(i>=j)
            return true;
        return false;
    }
};