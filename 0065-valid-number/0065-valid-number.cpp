class Solution {
public:
    bool isNumber(string s) {
        int n = s.size();
        //int sign = 1;
        int i=0;
        if(s[i]=='-' || s[i]=='+')
            ++i;
        
        bool num = false;
        while(i<n && isdigit(s[i]))
        {
            num = true;
            ++i;
        }
        if(num && i==n)
            return true;
        
        if( s[i]=='.')
        {
            ++i;
            while(i<n && isdigit(s[i])) // optional
            {
                ++i; 
                num = true;
            }
            if(num && i==n)
                return true;
        }
        
        if(num && (s[i]=='e' || s[i]=='E'))
        {
            ++i;
            if(s[i]=='-' || s[i]=='+')
                ++i;
            bool num2 =false;
            while(i<n && isdigit(s[i]))
            {
                num2 = true;
                ++i;
            }
            if(i==n && num2)
                return true;
        }
        return false;
    }
};