class Solution {
public:
    vector<vector<int>> pacificAtlantic1(vector<vector<int>>& heights) {
        
        int rows = heights.size();
        int cols = heights[0].size();
        
        vector<vector<int>> reach(rows,vector(cols,0));
        
        //vector<int> rmax(rows,0);
        //vector<int> cmax(cols,0);
        for(int r=0;r<rows;++r)
        {
            reach[r][0] |= 1;
            reach[r][cols-1] |= 2;
        }
        
        for(int c=0;c<cols;++c)
        {
            reach[0][c] |= 1;
            reach[rows-1][c] |= 2;
        }
        
        for(int r=1;r<rows;++r)
        {
            for(int c=1;c<cols;++c)
            {
                if( ((heights[r][c] >= heights[r-1][c]) &&  (reach[r-1][c] & 1)   )  || ((heights[r][c] >= heights[r][c-1]) &&  (reach[r][c-1] & 1)  ) )
                //if(((heights[r][c] >= heights[r-1][c]) || (heights[r][c] >= heights[r][c-1])) && ((reach[r-1][c] && 1) || (reach[r][c-1] && 1) ))
                    reach[r][c] |= 1;
            }
        }
        
        for(int r=rows-2;r>=0;--r)
        {
            for(int c=cols-2;c>=0;--c)
            {
                if( ((heights[r][c] >= heights[r+1][c]) &&  (reach[r+1][c] & 2)   )  || ((heights[r][c] >= heights[r][c+1]) &&  (reach[r][c+1] & 2)  ) )
                //if((heights[r][c] >= heights[r+1][c] || heights[r][c] >= heights[r][c+1]) && ((reach[r+1][c] && 2) || (reach[r][c+1] && 2) ))
                    reach[r][c] |= 2;
            }
        }
        
        vector<vector<int>> res;
        
        for(int r=0;r<rows;++r)
        {
            for(int c=0;c<cols;++c)
            {
                if(reach[r][c]==3)
                    res.push_back({r,c});
            }
        }
        
        return res;
    }
    
        vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
        int rows = heights.size();
        int cols = heights[0].size();
        
        vector<vector<int>> reachp(rows,vector(cols,-1));
        vector<vector<int>> reacha(rows,vector(cols,-1));
        
        function<void(int,int,int)> dfsa = [&](int r,int c,int val)
        {
            if(r<0 || c<0 || c>=cols || r>=rows || heights[r][c] < val ||  reacha[r][c] != -1)
                return;
            reacha[r][c] = 1;
            vector<vector<int>> dir{{0,-1},{-1,0},{1,0},{0,1} };
            
            for(int i=0;i<4;++i)
            {
                int r1 = r + dir[i][0];
                int c1 = c + dir[i][1];
                
                dfsa(r1,c1, heights[r][c]);
            }
        };
            
        function<void(int,int,int)> dfsp = [&](int r,int c,int val)
        {
            if(r<0 || c<0 || c>=cols || r>=rows || heights[r][c] < val ||  reachp[r][c] != -1)
                return;
            reachp[r][c] = 1;
            vector<vector<int>> dir{{0,-1},{-1,0},{1,0},{0,1} };
            
            for(int i=0;i<4;++i)
            {
                int r1 = r + dir[i][0];
                int c1 = c + dir[i][1];
                
                dfsp(r1,c1, heights[r][c]);
            }
        };
          
        for(int r=0;r<rows;++r)
        {
            dfsp(r,0,0);
            dfsa(r,cols-1,0);
        }
        
        for(int c=0;c<cols;++c)
        {
            dfsp(0,c,0);
            dfsa(rows-1,c,0);
        }
            
        vector<vector<int>> res;
        
        for(int r=0;r<rows;++r)
        {
            for(int c=0;c<cols;++c)
            {
                if(reacha[r][c]==1 && reachp[r][c]==1)
                    res.push_back({r,c});
            }
        }
        
        return res;
    }
};