class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> adj(n);
        vector<int> indegree(n,0);
        for(auto& r:relations){
            adj[r[0]-1].push_back(r[1]-1);
            indegree[r[1]-1]++;
        }
        map<int,vector<int>> progress;
        int t=0;
        for(int i=0;i<n;++i){
            if(indegree[i]==0)
                progress[time[i]].push_back(i);
        }
        while(true){
            auto it = progress.begin();
            int tend = it->first;
            auto vidx = it->second;
            for(auto idx:vidx)
                for(auto& id: adj[idx]){
                    if(--indegree[id]==0){
                        progress[tend + time[id] ].push_back(id);
                    }
                }
            progress.erase(it);
            if(tend> t)
                t = tend;
            if(progress.empty())
                break;
        }
        return t;
    }
};