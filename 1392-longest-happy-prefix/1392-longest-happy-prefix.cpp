class Solution {
public:
    vector<int> prefix(string s)
    {
        int n = s.size();
        int k=0;
        vector<int> pi(n,0);
        for(int i=1;i<n;++i)
        {
            while(k>0 && s[k]!=s[i])
                k = pi[k-1];
            if(s[k]==s[i])
                ++k;
            pi[i] = k;
        }
        return pi;
    }
    string longestPrefix(string s) {
        auto pre = prefix(s);
        return s.substr(0, pre.back());
    }
};