class Solution {
public:
    int rootCount(vector<vector<int>>& edges, vector<vector<int>>& guesses, int k) {
        int n = edges.size()+1;
        vector<vector<int>> adj(n);
        for(auto& e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        unordered_map<int,unordered_set<int>> gset;
        for(auto& g:guesses)
            gset[g[0]].insert(g[1]);
        int result=0;
        int gcount=0;
        map<pair<int,int>,int> dp;
        //vector<vector<int>> dp(n+1,vector<int>(n,-1));
        //vector<bool> visited(n,false);
        function<int(int,int)> dfs = [&](int node,int parent){
            if(dp.count({parent,node}))
                return dp[{parent,node}];
            //if(dp[parent][node] != -1)
            //    return dp[parent][node];
            int gcount = 0;
            for(auto& nei:adj[node]){
                if(nei!= parent){
                    if(gset[node].count(nei))
                        ++gcount;
                    gcount += dfs(nei,node);
                }
            }
            //return dp[parent][node] = gcount;
            return dp[{parent,node}] = gcount;
        };
        for(int i=0;i<n;++i){
            int gk = dfs(i,n);
            if(gk>=k)
                ++result;
        }
        
        return result;
    }
};