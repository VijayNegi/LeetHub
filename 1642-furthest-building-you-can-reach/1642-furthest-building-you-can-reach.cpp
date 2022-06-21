class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        //auto cmp = [](int l,int r){return l<r;};
        priority_queue<int> pq;
        int i=0;
        for(;i<heights.size()-1;++i) {
            int diff = heights[i+1] -  heights[i];
            if(diff>0) {
                if(diff<=bricks) {
                    pq.push(diff);
                    bricks -= diff;
                }
                else if(ladders>0) {
                    --ladders;
                    if(pq.size() && diff< pq.top()) {
                        bricks += pq.top();
                        pq.pop();
                        --i;
                    }
                }
                else
                    break;
                    
            }
        }
        return i;
    }
};