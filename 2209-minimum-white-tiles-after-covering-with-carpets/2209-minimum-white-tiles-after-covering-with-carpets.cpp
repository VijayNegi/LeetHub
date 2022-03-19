class Solution {
public:
    int minimumWhiteTiles(string floor, int nC, int cLen) {
        int n = floor.size();
        if(nC*cLen>=n)
            return 0;
        
        vector<int> sw(n-cLen+1,0);
        int count=0;
        int white=0;
        for(int i=0;i<n;++i)
        {
            if(floor[i]=='1')
                ++count,++white;
            if(i==cLen-1)
                sw[i-cLen+1] = count;
            if(i>=cLen)
            {
                if(floor[i-cLen]=='1')
                    --count;
                sw[i-cLen+1] = count;
            }
        }
        int result = white;
        function<void(int,int,int)> bt = [&](int pos,int visible,int remain)
        {
            
            if(pos>=n || remain==0)
            {
                result = min(result,visible);
                return;
            }
            while(pos<n)
            {
                if(sw[pos-cLen+1]>0)
                    bt(pos+cLen,visible-sw[pos-cLen+1],remain-1);
                ++pos;
            } 
        };
        vector<vector<int>> dp(n+1,vector(nC+1,-1));
         function<int(int,int)> bt1 = [&](int pos,int remain)
        {
            
            if(pos>=n || remain==0)
                return 0 ;
             
             if(dp[pos][remain]!=-1)
                 return dp[pos][remain];
             
             int covered = max(sw[pos-cLen+1]+bt1(pos+cLen,remain-1), bt1(pos+1,remain));
            return dp[pos][remain] = covered;
        };
        //bt(cLen-1,white,nC);
        int cov = bt1(cLen-1,nC);
        return white-cov;
    };
};