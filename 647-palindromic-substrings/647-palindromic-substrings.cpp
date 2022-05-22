class Solution {
public:
    int countSubstrings(string s) {
        int n =s.size();
        int result=0;
        for(int i=0;i<n;++i) {
            int l,r;
            l=r=i;
            while(l>=0 && r<n && s[l--]==s[r++]) {
                ++result;
            }
        }
        for(int i=0;i<n-1;++i) {
            int l,r;
            l=i;
            r=l+1;
            while(l>=0 && r<n && s[l--]==s[r++]) {
                ++result;
            }
        }
        return result;
        
    }
};