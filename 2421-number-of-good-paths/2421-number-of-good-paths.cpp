struct DSU{
    vector<int> parent,value,count;
    int goodPoint;
    DSU(int n, vector<int> _value):parent(n,0),value(_value),count(n,1),goodPoint(0){
        iota(parent.begin(),parent.end(),0);
    }
    int find(int id){
        if(parent[id]==id) return id;
        return parent[id] = find(parent[id]);
    }
    void merge(int id1,int id2){
        int pid1 = find(id1);
        int pid2 = find(id2);
        if(pid1==pid2) return;
        if(value[pid1] < value[pid2]){
            parent[pid1] = pid2;
            //++goodPoint;
        }
        else if(value[pid1] > value[pid2]){
            parent[pid2] = pid1;
            //++goodPoint;
        }
        else {
            parent[pid1] = pid2;
            //goodPoint += count[pid1]*count[pid2];
            //count[pid1] += count[pid2];
        }
    }
};
class Solution {
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
         int n = vals.size();
        vector<vector<int>> adj(n);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        map<int, vector<int>> valuesToNodes;
        for (int node = 0; node < n; node++) {
            valuesToNodes[vals[node]].push_back(node);
        }
        DSU dsu(n,vals);
        int goodPaths = 0;
        for (auto& [value, nodes] : valuesToNodes) {
            for (int node : nodes) {
                for (int neighbor : adj[node]) {
                    if (vals[node] >= vals[neighbor]) {
                            dsu.merge(node, neighbor);
                    }
                }
            }
            unordered_map<int, int> group;
            for (int u : nodes) {
                group[dsu.find(u)]++;
            }
            for (auto& [_, size] : group) {
                goodPaths += (size * (size + 1) / 2);
            }
        }
        return goodPaths;
    }
};