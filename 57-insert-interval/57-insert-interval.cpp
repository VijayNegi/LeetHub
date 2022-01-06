class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        int n = intervals.size();
        vector<vector<int>> result;
        
        // if(n==0)
        //     return result;
        
        int i=0;
        while(i<n && intervals[i][0] < newInterval[0])
            result.push_back(intervals[i++]);
        
        if(i>0)
        {
            if(result.back()[1] >= newInterval[0])
            {
                result.back()[1] = max(result.back()[1], newInterval[1]);
            }
            else
                result.push_back(newInterval); 
        }
        else
            result.push_back(newInterval);
        
        
        while(i<n)
        {
            if(result.back()[1] >= intervals[i][0])
            {
                result.back()[1] = max(result.back()[1], intervals[i][1]);
                ++i;
            }
            else
                result.push_back(intervals[i++]); 
        }
        return result;
       
    }
};