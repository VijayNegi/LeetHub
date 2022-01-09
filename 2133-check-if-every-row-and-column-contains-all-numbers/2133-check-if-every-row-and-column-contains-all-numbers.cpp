class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<bool>> count(2*n,vector<bool>(n,false));
        
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
            {
                int val = matrix[i][j]-1;
                count[i][val] = true;
                count[n+j][val] = true;
            }
        }
        
        for(auto& vec:count)
        {
            for(auto p:vec)
                if(!p)
                    return false;
        }
        return true;
    }
};