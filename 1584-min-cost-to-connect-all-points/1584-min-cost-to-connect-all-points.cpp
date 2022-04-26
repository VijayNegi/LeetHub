using wto = pair<int,int>;
class Solution {
public:
    // MST : 1811
    int minCostConnectPoints1(vector<vector<int>>& points) {
        int n = points.size();
        vector<int> visited(n,false);
        priority_queue<vector<int>,vector<vector<int>>, greater<>> pq;
        pq.push({0,0});
        int cost=0;
        int count = 0;
        while(!pq.empty())
        {
            auto v = pq.top();
            pq.pop();
            if(visited[v[1]])
                continue;
            int node = v[1];
            for(int i=0;i<n;++i)
            {
                if(!visited[i] && i!=node)
                {
                    int d = abs(points[node][0] - points[i][0]) + abs(points[node][1] - points[i][1]);
                    pq.push({d,i});
                }
            }
            visited[node] = true;
            cost += v[0];
            ++count;
            if(count==n)
                break;
        }
        return cost;
    }
    
     int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        auto cmd = [&](wto& left, wto& right){ return left.second > right.second;};
        priority_queue<wto,vector<wto>, decltype(cmd)> pq(cmd);
        vector<bool> visited(n,false);
        int count =0;
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
            ++count;
            if(count==n)
                break;
            
            pushnegighbours(currp.first);
        }
        return cost;
    }
};