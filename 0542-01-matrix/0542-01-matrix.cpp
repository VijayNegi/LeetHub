class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        
        auto checkTL = [&](int r,int c)
        {
            int result = INT_MAX/2;
            if(r > 0)
                result = min(result, mat[r-1][c]+1 );
            if(c > 0)
                result = min(result, mat[r][c-1]+1 );
            return result;
        };
        auto checkBR = [&](int r,int c)
        {
            int result = INT_MAX/2;
            if(r < rows-1)
                result = min(result, mat[r+1][c]+1 );
            if(c < cols-1)
                result = min(result, mat[r][c+1]+1 );
            return result;
        };
        
        // Top Left to Bottom Right
        for(int r=0;r<rows;++r)
        {
            for(int c=0;c<cols;++c)
            {
                if(mat[r][c]>0)
                {
                    mat[r][c]=checkTL(r,c);   
                }
            }
        }
        
        // Bottom Right to Top Left
        for(int r=rows-1;r>=0;--r)
        {
            for(int c=cols-1;c>=0;--c)
            {
                if(mat[r][c]>0)
                {
                    mat[r][c]= min(mat[r][c],checkBR(r,c));   
                }
            }
        }
        return mat;
    }
};