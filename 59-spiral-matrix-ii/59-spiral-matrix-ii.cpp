class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> mat(n,vector(n,0));
        mat[0][0] = 1;
        int val=2;
        int rows = n, cols = n;
        int rmin = 0,cmin = 0;
        vector<vector<int>> dir{{0,1},{1,0},{0,-1},{-1,0}};
        int k=0;
        int r=0,c=0;
        while(rows>0 && cols>0)
        {
            int r1 = r+dir[k][0];
            int c1 = c+dir[k][1];
            if(r1<rmin || r1>=rows || c1<cmin || c1>=cols)
            {
                if(k==0)       ++rmin;
                else if(k==1)  --cols;
                else if(k==2)  --rows;
                else if(k==3)  ++cmin;
                k = (k+1)%4;
                continue;
            }
            r=r1; c = c1;
            mat[r][c] = val++;
        }
        return mat;
    }
};