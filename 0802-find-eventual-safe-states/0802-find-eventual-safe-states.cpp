class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> incoming(n);
        for(int i=0;i<n;++i){
            for(auto& destination: graph[i]){
                incoming[destination].push_back(i);
            }
        }
        vector<unordered_set<int>> outgoing(n);
        for(int i=0;i<n;++i){
            outgoing[i].insert(begin(graph[i]),end(graph[i]));
            //outgoing[i].erase(i);
        }
        //vector<bool> safe(n,false);
        vector<int> safe;
        for(int i=0;i<n;++i){
            if(outgoing[i].empty())
                safe.push_back(i);
        }
        set<int> result;
        while(safe.size()){
            result.insert(safe.begin(),safe.end());
            vector<int> temp;
            for(auto& i:safe){
                //cout<<i<<endl;
                for(auto& d:incoming[i]){
                    outgoing[d].erase(i);
                    if(outgoing[d].empty())
                        temp.push_back(d);
                }
                incoming[i].clear();
            }
            swap(temp,safe);
        }
        
        return {result.begin(),result.end()};
    }
};