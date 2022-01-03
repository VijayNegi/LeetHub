class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int res = 0;
        for(int i=0;i<n-k;++i)
        {
            int j = i;
            int k1 = k;
            for(j=i+1;j<n && k1>=0;++j)
            {
                if(s[i]==s[j])
                    continue;
                else
                    --k1;
            }
            res = max(res,j-i+k1);
        }
        return min(res,n);
    }
};