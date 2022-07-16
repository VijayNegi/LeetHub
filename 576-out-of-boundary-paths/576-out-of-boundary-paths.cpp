const int mod = 1e9+7;
class Solution {
public:
    // dfs without memo : TLE
    int findPaths1(int m, int n, int maxMove, int startRow, int startColumn) {
        function<int(int,int,int)> dfs = [&](int r,int c,int moves){
            if(r<0 || c<0 || r>=m || c>=n)
                return 1;
            if(moves<=0)
                return 0;
            return dfs(r-1,c,moves-1) + dfs(r,c-1,moves-1) 
                    + dfs(r+1,c,moves-1) + dfs(r,c+1,moves-1);
        };
        return dfs(startRow,startColumn,maxMove);
    }
    // iterative
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<int> curr(n*m,0),temp(n*m,0);
        curr[startRow*n + startColumn] = 1;
        long result=0;
        function<bool(int,int)> valid = [n,m](int r,int c) {
            if(r<0 || c<0 || r>=m || c>=n)
                return false;
            return true;
        };
        for(int k=0;k<maxMove;++k) {
            fill(begin(temp),end(temp),0);
            for(int r=0;r<m;++r)
                for(int c=0;c<n;++c) {
                    long ways=0;
                    if(c==0) ++ways;
                    if(r==0) ++ways;
                    if(r==m-1) ++ways;
                    if(c==n-1) ++ways;
                    result += ways*curr[r*n+c];
                    result %= mod;
                    
                    if(valid(r+1,c))
                        temp[(r+1)*n+c] = ((long)curr[r*n+c]+temp[(r+1)*n+c])%mod ;
                    
                    if(valid(r-1,c)) 
                        temp[(r-1)*n+c] = ((long)curr[r*n+c]+temp[(r-1)*n+c])%mod ;
                     
                    if(valid(r,c+1))
                        temp[r*n+c+1] = ((long)curr[r*n+c]+temp[r*n+c+1])%mod ;
                        
                    if(valid(r,c-1)) 
                        temp[r*n+c-1] = ((long)curr[r*n+c]+temp[r*n+c-1])%mod ;
                }
            swap(curr,temp);
        }
        return result;
    }
};