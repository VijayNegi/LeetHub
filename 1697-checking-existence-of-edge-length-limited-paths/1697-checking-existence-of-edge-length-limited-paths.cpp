class UnionFind 
{
    vector<int> id;
public:
    UnionFind(int n) : id(n) {
        iota(begin(id), end(id), 0);
    }
    void connect(int a, int b) {
        int x = find(a), y = find(b);
        if (x == y) return;
        id[x] = y;
    }
    bool connected(int i, int j) { return find(i) == find(j); }
    int find(int a) {
        return id[a] == a ? a : (id[a] = find(id[a]));
    }
};
class Solution {
public:
    // self : TLE , Floyd Warshall 
    vector<bool> distanceLimitedPathsExist1(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        vector<vector<int>> adj(n,vector(n,INT_MAX));

        for(auto& e: edgeList){
            adj[e[0]][e[1]] = min(adj[e[0]][e[1]] ,e[2]);
            adj[e[1]][e[0]] = min(adj[e[1]][e[0]] ,e[2]);
        }
        
        for(int k=0;k<n;++k){
            for(int i=0;i<n;++i){
                for(int j=0;j<n;++j){
                    if(i==j) continue;
                    adj[i][j] = min(adj[i][j], max(adj[i][k],adj[k][j] ) );
                }
            }
        }
        int q = queries.size();
        vector<bool> ans(q,false);
        for(int i=0;i<q;++i){
            //cout<<adj[queries[i][0]][queries[i][1]]<<endl;
            ans[i] = adj[queries[i][0]][queries[i][1]] < queries[i][2];
        }
        return ans;
    }
    
    // disjoint-set
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& E, vector<vector<int>>& Q) {
        vector<bool> ans(Q.size());
        for (int i = 0; i < Q.size(); ++i) Q[i].push_back(i);
        sort(begin(Q), end(Q), [&](auto &a, auto &b) { return a[2] < b[2]; });
        sort(begin(E), end(E), [&](auto &a, auto &b) { return a[2] < b[2]; });
        UnionFind uf(n);
        int i = 0;
        for (auto &q : Q) { // traverse the queries from small limit to large limit
            int u = q[0], v = q[1], limit = q[2], qid = q[3];
            for (; i < E.size() && E[i][2] < limit; ++i) uf.connect(E[i][0], E[i][1]); // visit the edges that are smaller than the limit
            ans[qid] = uf.connected(u, v);
        }
        return ans;
    }

};