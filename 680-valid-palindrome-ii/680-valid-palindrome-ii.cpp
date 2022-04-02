class Solution {
public:
    bool validPalindrome(string s) {
        int l=0,r=s.size()-1;
        while(l<r)
            if(s[l]==s[r])
                ++l,--r;
            else
                break;
        if(l>=r)
            return true;
        int l1=l+1;
        int r1=r;
        while(l1<r1)
            if(s[l1]==s[r1])
                ++l1,--r1;
            else
                break;
        if(l1>=r1)
            return true;
        l1=l;r1=r-1;
        while(l1<r1)
            if(s[l1]==s[r1])
                ++l1,--r1;
            else
                break;
        if(l1>=r1)
            return true;
        return false;
    }
};