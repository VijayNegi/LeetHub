class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> result;
        int rows = land.size();
        int cols = land[0].size();
        for(int i=0;i<rows;++i){
            int s = 0;
            for(int j=0;j<cols;++j){
                if(i!=0 && land[i][j]) land[i][j] += land[i-1][j];
                if(land[i][j]) ++s;
                else if(s && (i== rows-1 || (land[i+1][j-1]!= 1 ))){
                    result.push_back({i-land[i][j-1] +1 , j - s , i,j-1 });
                }
                if(!land[i][j])  s=0;
            }
            if(s && (i== rows-1 || (land[i+1][cols-1]!= 1 ))) 
                result.push_back({ i- land[i][cols-1] +1 , cols - s, i,cols-1 });

        }
        return result;
    }
};