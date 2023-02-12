class Solution {
public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size()+1;
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
        for(int i=1;i<n;++i){
            if(inDegree[i]==1)
                leafs.push(i);
        }
        long long fuel=0;
        long long full=0;
        while(leafs.size() ){
            int k = leafs.size();
            //cout<<k<<"-"<<full <<endl;
            //fuel += full;
            while(k--){
                auto node = leafs.front();
                leafs.pop();
                //if(node==0) continue;
                ++fuel;
                fuel += (seat[node]-1)/seats;
                //full += seat[node]/seats;
                //seat[node] %=seats;
                for(auto nei:adj[node]){
                    inDegree[nei]--;
                    seat[nei]+= seat[node];
                    if(nei !=0 && inDegree[nei]==1){
                        leafs.push(nei);
                    }  
                }
            }
        }
        //cout<<"full"<<full<<endl;
        return fuel;
    }
};