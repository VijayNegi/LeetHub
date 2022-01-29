class Solution {
public:
    // mono stack
    int largestRectangleArea1(vector<int>& heights) {
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
    // mono stack again but somewhat cleaner
    int largestRectangleArea(vector<int>& heights) {
        list<int> s;
        int n= heights.size();
        int result=0;
        for(int i=0;i<n;++i)
        { 
            
            while(!s.empty() && heights[s.back()] >= heights[i])
            {
                int H = heights[s.back()];
                s.pop_back();
                int W =  (s.empty()? i: i- s.back()-1);
                result = max(result,H*W);
            }
            s.push_back(i);
        }
        while(!s.empty())
        {
            int H = heights[s.back()];
            s.pop_back();
            int W =(s.empty()? n: n- s.back()-1);
            result = max(result,H*W);
        }
        return result;
    }
};