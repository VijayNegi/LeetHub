class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(), [](vector<int>& l,vector<int>& r){
            if(l[1]==r[1]) return l[0]<r[0];
            return l[1]<r[1];
        });
        int result=1,end=points[0][1];
        for(int i=1;i<points.size();++i){
            if(end< points[i][0]){
                end = points[i][1];
                ++result;
            }
        }
        return result;
    }
};