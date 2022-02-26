class Solution {
public:
    vector<int> prefix_function(string s)
    {
        int n = s.size();
        vector<int> pi(n,0);
        int k=0;
        for(int i=1;i<n;++i)
        {
            while(k>0 && s[k] != s[i])
                k = pi[k-1];
            if(s[k]==s[i])
                ++k;
            pi[i] = k;
        }
        return pi;
    }
    bool compare(string s, int k)
    {
        int n = s.size();
        if(n%k)
            return false;
        for(int i=k;i<n;i+=k)
        {
            int ii=i;
            for(int j=0;j<k;++j,++ii)
                if(s[ii]!=s[j])
                    return false;
        }
        
        return true;
    }
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        // if(n%2)
        //     return false;
        int k = 1;
        while(k<n)
        {
            if(compare(s,k))
                return true;
            ++k;
        }
        return false;
    }
};