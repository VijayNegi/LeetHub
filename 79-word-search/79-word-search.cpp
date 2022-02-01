class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();
        
        int dirx[4] = {1,0,-1,0};
        int diry[4] = {0,1,0,-1};
        function<bool(int,int,int)> dfs = [&](int r,int c,int idx)
        {
            char ch = board[r][c];
            if(ch =='#' || ch!=word[idx])
                return false;
            if(idx== word.size()-1)
                return true;
            board[r][c] = '#';
            for(int dir=0;dir < 4;++dir)
            {
                int rr,cc;
                rr = r+dirx[dir];
                cc = c+diry[dir];
                
                if(rr<0 || rr>= rows) continue;
                if(cc<0 || cc>= cols) continue;
                if(dfs(rr,cc,idx+1))
                    return true;
            }
            board[r][c] = ch;
            return false;
        };
        
        
        for(int r = 0;r<rows;++r)
        {
            for(int c = 0;c<cols;++c)
            {
                if(board[r][c] == word[0] && dfs(r,c,0))
                    return true;
            }
        }
        return false;
    }
};