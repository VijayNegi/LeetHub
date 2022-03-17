class Solution {
public:
    int scoreOfParentheses(string s) {
        int idx=0;
        return score(s,idx)/2;
    }
    
    int score(string& s, int& idx)
    {
        if(idx == s.size())
            return 0;
        
        int result = 0;
        while(idx < s.size())
        {
            if(s[idx]==')')
            {
                ++idx;
                break;
            }
            else 
            {
                result += score(s,++idx);
            }
        }
        return result==0?1:2*result;
    }
};