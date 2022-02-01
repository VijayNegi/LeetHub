class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string res;
        int open = 0;
        for(auto a:s)
        {
           
            if(a==')' && open==0)
                continue;
            if(a=='(')
                ++open;
            else if(a==')')
                --open;
            res.append(1,a);
        }
        s = res;
        res.clear();
        reverse(s.begin(),s.end());
        int close=0;
        for(auto a:s)
        {
           
            if(a=='(' && close==0)
                continue;
            if(a==')')
                ++close;
            else if(a=='(')
                --close;
            res.append(1,a);
        }
        reverse(res.begin(),res.end());
        
        return res;
        
    }
};