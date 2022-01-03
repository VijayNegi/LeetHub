class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        
        sort(begin(intervals),end(intervals),[](vector<int>& a,vector<int>&b){ 
            if(a[0]==b[0])
                return a[1] < b[1];
            return a[0] < b[0];
            });
        int res=0;
        int last = intervals[0][1];
        for(int i=1;i<n;++i)
        {
            if(last <= intervals[i][0])
                last = intervals[i][1];
            else
            {
                last = min(last,intervals[i][1]);
                ++res; // remove the current 
            }
                
        }
        return res;
    }
};