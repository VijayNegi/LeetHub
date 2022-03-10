class Solution {
    set<string> res;
public:
    //  (( )( ) 
    void removeOpen(string s,int i, vector<int> inO,vector<int> inC)
    {
        //cout<<"rOpen "<<s<<endl;
        if(i>= inO.size())
        {
            removeClose(s,0,inO,inC);
        }
        else
        {
            int ii = inO[i];
            //ii += i;
            for(int k=s.size()-1;k>=ii;--k)
            {
                if(s[k]=='(')
                {
                    string p = s;
                     removeOpen(p.erase(k,1),i+1,inO,inC); 
                }
            }
        }
    }
    
    void removeClose(string s,int i, vector<int> inO,vector<int> inC)
    {
        //cout<<"rClose "<<s<<endl;
        if(i>= inC.size())
            res.insert(s);
        else
        {
            int ii = inC[i];
            ii -= i;
            for(int k=0;k<=ii;++k)
            {
                if(s[k]==')')
                {
                    string p = s;
                    p.erase(k,1);
                     removeClose(p,i+1,inO,inC); 
                }
            }
        }
            
    }
    
    vector<string> removeInvalidParentheses(string s) {
        int n = s.size();
        vector<int> opn;
        vector<int> clo;
        
        
        int count=0;
        // invalid closes
        for(int i=0;i<n;++i)
        {
            if(s[i]=='(')
                ++count;
            else if(s[i]==')')
                --count;
            if(count<0)
            {
                clo.push_back(i);
                count = 0;
            }    
        }
        // invalid open
        count=0;
        for(int i=n-1;i>=0;--i)
        {
            if(s[i]=='(')
                ++count;
            else if(s[i]==')')
                --count;
            if(count>0)
            {
                opn.push_back(i);
                count = 0;
            }   
        }
        //cout<<opn.size()<<" -- "<<clo.size()<<endl;
        removeOpen(s,0, opn,clo);
        
        vector<string> res1(res.begin(),res.end());
        return res1;
    }
};