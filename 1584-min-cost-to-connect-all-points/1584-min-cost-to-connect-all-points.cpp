class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
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
};