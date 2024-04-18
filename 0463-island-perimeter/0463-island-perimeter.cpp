class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int count=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                //Vertical
                if(i==0)
                {
                    if(grid[i][j]==1)
                        count++;
                }
                else
                {
                    if(grid[i][j] + grid[i-1][j]==1)
                        count++;
                }
                
                if(i==grid.size()-1)
                {
                    if(grid[i][j]==1)
                        count++;
                }
                
                //Horizontal
                
                if(j==0)
                {
                    if(grid[i][j]==1)
                        count++;
                }
                else
                {
                    if(grid[i][j] + grid[i][j-1]==1)
                        count++;
                }
                
                if(j==grid[0].size()-1)
                {
                    
                    if(grid[i][j]==1)
                        count++;
                }
                
            }
        }
        return count;
    }
};