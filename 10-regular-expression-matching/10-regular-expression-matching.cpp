class Solution {
public:
    bool isMatch(string s, string p) {
        
        return match(s,s.size()-1,p,p.size()-1);
    }
    bool match(string& s,int si, string& p,int pi)
    {
        //cout<<si<<" "<<pi<<endl;
        if(si==-1 && pi==-1)
            return true;
        if(pi==-1) // pattern could have redundent match so wait like a* at beginning
            return si==-1;
        if(p[pi]=='*')
        {
            if(match(s,si,p,pi-2))
                return true;
            while(si>=0 && (s[si]==p[pi-1] || p[pi-1]=='.'))
                if(match(s,--si,p,pi-2))
                    return true;
            return false;
        }
        else if(si>=0)
        {
            if((s[si]==p[pi] || p[pi]=='.') && match(s,si-1,p,pi-1) )
                return true;
        }
        return false;
        
    }
};