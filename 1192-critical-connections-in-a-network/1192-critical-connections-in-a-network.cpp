class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for(auto ed:connections) {
            adj[ed[0]].push_back(ed[1]);
            adj[ed[1]].push_back(ed[0]);
        }
        
        vector<int> idx(n,-1);
        vector<int> low(n,-1);
        int id = 0;
        vector<vector<int>> result;
        function<void(int,int)> dfs = [&](int node,int parent) {
            
            if(idx[node] != -1)
                return;
            //cout<<node<<endl;
            idx[node] = id++;
            low[node] = idx[node];// lowest self rechable
            for(auto ed:adj[node]) {
                if(ed == parent)
                    continue;
                dfs(ed,node);
                low[node] = min(low[node],low[ed]);
                if(idx[node] < low[ed])
                    result.push_back({node,ed});
                
            }
            //cout<<node<<" "<<low[node]<<endl;
        };
        dfs(0,-1);
        return result;
    }
};