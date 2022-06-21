class Solution {
public:
    // self : 123 ms
    int furthestBuilding1(vector<int>& heights, int bricks, int ladders) {
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
    // cleaner 221 ms
    int furthestBuilding2(vector<int>& hs, int bricks, int ladders) {
        priority_queue<int> pq;
        for (int i = 1; i < hs.size(); ++i) {
            int d = hs[i] - hs[i - 1];
            if (d > 0) {
                pq.push(d);
                bricks -= d;
                if (bricks < 0) {
                    --ladders;
                    bricks += pq.top();
                    pq.pop();
                    if (bricks < 0 || ladders < 0)
                        return i - 1;

                }
            }
        }
        return hs.size() - 1;
    }  
    // self old
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        
        int curr=0;
        int len = heights.size();
        long sum=0;
        vector<int> incDiff;
        while(curr<len-1)
        {
            int diff = heights[curr+1] - heights[curr];
            if(diff<=0)
            {
                ++curr;
                continue;
            }
            else
            {
                incDiff.push_back(diff);
                sum+=diff;
                push_heap(incDiff.begin(), incDiff.end());
                ++curr;
                if(sum>bricks)
                {
                    if(ladders)
                    {
                        int bri = incDiff.front();
                        pop_heap(incDiff.begin(), incDiff.end());
                        incDiff.pop_back();
                        sum-=bri;
                        --ladders;
                    }
                    else
                    {
                        --curr;
                        break;
                    }
                    
                }
            }
        }
        return curr;
    }
};