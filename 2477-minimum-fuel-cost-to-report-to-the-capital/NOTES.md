class Solution {
public:
long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
int n = roads.size();
vector<int> inDegree(n,0);
vector<vector<int>> adj(n);
for(auto& r:roads){
adj[r[0]].push_back(r[1]);
adj[r[1]].push_back(r[0]);
inDegree[r[0]]++;
inDegree[r[1]]++;
}
queue<int> leafs;
for(int i=0;i<n;++i){
if(indegree[i]==1)
leafs.push(i);
}
long long fuel=0;
while(leafs.size()){
}
}
};