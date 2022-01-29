class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // int , int , fromIndex and minHeight
        list<pair<int,int>> mqueue;
        int n= heights.size();
        int result=0;
        for(int i=0;i<n;++i)
        { 
            int preIdx = i;
            while(!mqueue.empty() && mqueue.back().second >= heights[i])
            {
                preIdx = mqueue.back().first;
                
                int area = mqueue.back().second * (i-mqueue.back().first);
                 mqueue.pop_back();
                 result = max(result,area);
            }
            mqueue.push_back({preIdx,heights[i]});
        }
        while(!mqueue.empty())
        {
            int area = mqueue.back().second * (n-mqueue.back().first);
            mqueue.pop_back();
            result = max(result,area);
        }
        return result;
    }
};