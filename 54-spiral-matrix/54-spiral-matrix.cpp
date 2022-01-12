class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        int r=0,c=0;
        
        vector<vector<int>> dir = {{0,1},{1,0},{0,-1},{-1,0}};
        
        int cdir = 0;
        int dist = 0;
        vector<int> result;
        
        
        while(rows>0 && cols>0)
        {
            cout<<"r="<<r<<" c="<<c<<endl;
            result.push_back(matrix[r][c]);

            ++dist;
            cout<<"Rows="<<rows<<" cols="<<cols<<" dist="<<dist<<endl;
            if(cdir==0 && dist>=cols)
                ++cdir,rows-=1, dist=0;
            else if(cdir==1 && dist>=rows)
                ++cdir,cols-=1, dist=0;
            else if(cdir==2 && dist>=cols)
                ++cdir,rows-=1, dist=0;
            else if(cdir==3 && dist>=rows)
                cdir=0,cols-=1, dist=0;
            
            r += dir[cdir][0];
            c += dir[cdir][1];
        }
        
        return result;
        
    }
};