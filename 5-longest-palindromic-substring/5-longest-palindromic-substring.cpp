class Solution {
public:
    string longestPalindrome(string s) {
        int len=0;
        int n = s.size();
        string result;
        for(int i=0;i<n;++i) {
            int l=i,r=i;
            while(l>=0 && r<n && s[l]==s[r]) --l,++r;
            if(r-l-1>len) {
                len = r-l-1;
                result = s.substr(l+1,len);
            }
            l=i,r=i+1;
            while(l>=0 && r<n && s[l]==s[r]) --l,++r;
            if(r-l-1>len) {
                len = r-l-1;
                result = s.substr(l+1,len);
            }
        }
        return result;
    }
};