class Solution {
public:
    vector<int> findMinHeightTrees1(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto& ed:edges)
        {
            adj[ed[0]].push_back(ed[1]);
            adj[ed[1]].push_back(ed[0]);
        }
        
        vector<bool> vis(n,false);
        function<int(int)> dfs = [&](int v)
        {
            if(vis[v])
                return 0;
            vis[v] = true;
            int h = 0;
            for(auto& e:adj[v])
            {
                h = max(dfs(e),h);
            }
            return h+1;
        };
        
        int minH = n;
        vector<int> res;
        
        for(int i=0;i<n;++i)
        {
            fill(vis.begin(),vis.end(),false);
            if(adj[i].size()==1)
                continue;
            int h = dfs(i);
            if(h<minH)
            {
                res.clear();
                res.push_back(i);
                minH = h;
            }
            else if(h==minH)
                res.push_back(i);
            
        }
        return res;
    }
    
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1)
            return {0};
        vector<set<int>> adj(n);
        for(auto& ed:edges)
        {
            adj[ed[0]].insert(ed[1]);
            adj[ed[1]].insert(ed[0]);
        }
        
        //vector<bool> vis(n,false);
        
        int minH = n;
        set<int> res;
        // get all leaf nodes
        
        
        for(int i=0;i<n;++i)
        {
            if(adj[i].size()==1)
            {
                res.insert(i);
                //vis[i] = true;
                //adj[*(adj[i].begin())].erase(i);
                //adj[i].clear();
            }
                
        }
        int visited = n - res.size();
        while(visited>0)
        {
            //cout<<"visited="<<visited<<endl;
            // if(visited == 0 )
            //     break;
            set<int> temp;
            
            for(auto& v: res)
            {
                //cout<<v<<"  = "<<endl;
                for(auto& v1: adj[v])
                {
                    //cout<<v1<<endl;
                   
                    adj[v1].erase(v);
                    
                    if(adj[v1].size()<=1)
                    {
                        //cout<<v1<<",";
                        temp.insert(v1);
                    }
                }
                //cout<<endl;
                
            }
            //cout<<endl;
            
//             visited -= temp.size();
            
//             if(visited<=2)
//             {
//                 //res = temp;
//                 break;
//             }
//             else
            {
               
                res = temp;
                visited -= res.size();
            }
            
        }
        
        vector<int> res1(res.begin(),res.end());
        
        return res1;
    }
};