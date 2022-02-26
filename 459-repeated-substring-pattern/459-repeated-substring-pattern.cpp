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
    // 1581 ms
    bool repeatedSubstringPattern1(string s) {
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
    
     bool repeatedSubstringPattern(string s) {
        int n = s.size();
        vector<int> pi = prefix_function(s);
         //cout<<pi[n-1]<<endl;
         int patternLen = n- pi[n-1];
         if(patternLen==n)
             return false;
         if(n%patternLen)
             return false;
         return true;
        if(n%2==0)
        {
            return pi[n-1]>= (n/2);
        }
         else
         {
                return pi[n-1]> (n/2);
         }
       
        return false;
    }
};