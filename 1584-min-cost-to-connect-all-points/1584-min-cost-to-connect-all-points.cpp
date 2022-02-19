using wto = pair<int,int>;
class Solution {
public:
    // MST : minimum spanning tree
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        auto cmd = [&](wto& left, wto& right){ return left.second > right.second;};
        priority_queue<wto,vector<wto>, decltype(cmd)> pq(cmd);
        vector<bool> visited(n,false);
        
        int p = 0; // point index
         pq.push({0,0});
        function<void(int)> pushnegighbours = [&](int node)
        {
            for(int i=0;i<n;++i)
            {
                if(!visited[i] && i!=node)
                {
                    int dist = abs(points[node][0] - points[i][0] ) + abs(points[node][1] - points[i][1]);
                    pq.push({i,dist});
                }
            }
            
        };
        int cost = 0;
        while(!pq.empty())
        {
            auto currp = pq.top();
            pq.pop();
            
            if(visited[currp.first])
                continue;
            visited[currp.first] = true;
            cost += currp.second;
            pushnegighbours(currp.first);
        }
        
        return cost;
        
    }
};