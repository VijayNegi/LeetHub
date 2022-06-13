class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        //vector<int> res = triangle[0];
        for(int i=1;i<n;++i) {
            triangle[i][0] += triangle[i-1][0];
            for(int j=1;j<i;++j) {
                triangle[i][j] += min(triangle[i-1][j],triangle[i-1][j-1]);
            }
            triangle[i][i] += triangle[i-1][i-1];
        }
        return *min_element(triangle[n-1].begin(),triangle[n-1].end());
    }
};