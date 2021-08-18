class Solution {
public:
    int numDecodings(string s) {
        vector<int> mem(s.size()+1,-1);
        return dfs(s,0,mem);
    }
    
    int dfs(string s, int idx,vector<int>& mem)
    {
        
        if(idx>=s.size())
            return 1;
        if(mem[idx]>=0)
            return mem[idx];
        
        if(s[idx] == '0')
        {
            mem[idx] = 0;
            return 0;
        }
            
        
        if(idx == s.size() - 1)
        {
            mem[idx] = 1;
            return 1;
        }
            
        
        int ways = 0;
        
        if(s[idx]=='1')
        {
            ways+= dfs(s,idx+1,mem);
            ways+= dfs(s,idx+2,mem);
        }
        else if(s[idx]=='2')
        {
            if(s[idx+1]<='6')
            {
                ways+= dfs(s,idx+1,mem);
                ways+= dfs(s,idx+2,mem);
            }
            else
                ways+= dfs(s,idx+1,mem);
        }
        else
            ways+= dfs(s,idx+1,mem);
        
        mem[idx] = ways;
        return ways;
    }
    
};