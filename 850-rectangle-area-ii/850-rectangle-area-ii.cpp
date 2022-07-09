const int mod = 1e9 + 7;
class Solution {
public:
    int rectangleArea(vector<vector<int>>& rectangles) {
        long area=0;
        int n = rectangles.size();
        sort(begin(rectangles),end(rectangles));
        int currx=0;
        int rectid=0;
        auto cmp = [&](int l,int r) {return rectangles[l][2]>rectangles[r][2];};
        priority_queue<int,vector<int>,decltype(cmp)> pq(cmp);
        unordered_set<int> currRects;
        while(true) {
            
            while(pq.size() && rectangles[pq.top()][2] <= currx ) {
                currRects.erase(pq.top());
                pq.pop();
            }
 
            if(pq.empty() && rectid<n) {
                currx = rectangles[rectid][0];
                currRects.insert(rectid);
                pq.push(rectid++);
            }
            if(pq.empty())
                break;
            
            int maxx = rectangles[pq.top()][2];
            if(rectid<n)
                maxx = min(rectangles[rectid][0],maxx);
            
            vector<pair<int,int>> yseg;
            long maxy = 0;
            for(auto i:currRects) {
                yseg.push_back({rectangles[i][1],rectangles[i][3]});
            }
            sort(begin(yseg),end(yseg));
            int y=-1;
            for(auto s:yseg) {
                if(y<s.second) {
                    maxy += s.second - max(s.first,y);
                    y = s.second;
                }
            }
  
            long size = (maxx- currx) * maxy;
            //cout<<rectid<<" "<<(maxx- currx)<<"  "<<maxy<<"  "<<maxx<<endl;
           
            area += size;
            currx = maxx ;
            
            while(rectid <n && rectangles[rectid][0] <= currx) {
                currRects.insert(rectid);
                pq.push(rectid++);
            }
        }
        return area%mod;
    }
};

