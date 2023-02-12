class Solution {
public:
    // self
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size()+1; // no of nodes 
        vector<int> inDegree(n,0);
        vector<vector<int>> adj(n);
        for(auto& r:roads){
            adj[r[0]].push_back(r[1]);
            adj[r[1]].push_back(r[0]);
            inDegree[r[0]]++;
            inDegree[r[1]]++;
        }
        vector<int> seat(n,1);
        queue<int> leafs;
        for(int i=1;i<n;++i){ // ignore capital
            if(inDegree[i]==1)
                leafs.push(i);
        }
        long long fuel=0;
        while(leafs.size() ){
            auto node = leafs.front();
            leafs.pop();
            ++fuel;
            fuel += (seat[node]-1)/seats;
            for(auto nei:adj[node]){
                inDegree[nei]--;
                seat[nei]+= seat[node];
                if(nei !=0 && inDegree[nei]==1){ // ignore capital
                    leafs.push(nei);
                }  
            }
            
        }
        return fuel;
    }
};