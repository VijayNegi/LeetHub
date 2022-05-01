class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i = s.size()-1;
        int j = t.size()-1;
        while(i>=0 || j>=0)
        {
            int skip=0;
            while(i>=0 && (s[i]=='#' || skip))
            {
                if(s[i] == '#')
                        ++skip,--i;
                    else
                        --skip,--i;
            }
            skip=0;
            while(j>=0 && (t[j]=='#' || skip))
            {
                if(t[j] == '#')
                        ++skip,--j;
                    else
                        --skip,--j;
            }
            if(i<0 || j<0)
                break;
            if(s[i] != t[j])
                    return false;
            --i,--j;
        }
        
        if(i>=0 || j>=0)
            return false;
        return true;
    }
};