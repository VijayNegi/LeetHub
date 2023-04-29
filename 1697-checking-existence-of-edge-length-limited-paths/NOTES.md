class Solution {
public:
vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
vector<unordered_map<int,int>> adj(n);
for(auto& e: edgeList){
if(adj[e[0]][e[1]] == 0 ){
adj[e[0]][e[1]] = e[2];
adj[e[1]][e[0]] = e[2];
}
else {
adj[e[0]][e[1]] = min(adj[e[0]][e[1]], e[2]);
adj[e[1]][e[0]] = min(adj[e[1]][e[0]], e[2]);
}
}
vector<vector<int>> maxPath(n,vector(n,0));
for(int k=0;k<n;++k){
for(int i=0;i<n;++i){
for(int j=0;j<n;++j){
if(i==j) continue;
maxPath[i][j] = max(maxPath[i][j], max(adj[i][k],adj[k][j] ) );
}
}
}
int q = queries.size();
vector<bool> ans(q,false);
for(int i=0;i<q;++i){
cout<<maxPath[queries[i][0]][queries[i][1]]<<endl;
ans[i] = maxPath[queries[i][0]][queries[i][1]] < queries[i][2];
}
return ans;
}
};