using pi = pair<int,int>;
class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        unordered_set<int> visited;    // node, state
        queue<pi> que;
        int n = graph.size();
        for(int i=0;i<n;++i)
        {
            pi p{i,1<<i};
            que.push(p);
            int hash = (1<<(i+12)) | p.second ; 
            visited.insert(hash);
        }
        int cost = 0;
        int endState = (1<< n) - 1;
        //cout<<"end "<<endState<<endl;
        int count = que.size();
        while(que.size())
        {
            if(count == 0 )
            {
                count = que.size();
                ++cost;
                //cout<<cost<<endl;
            }
            
            pi curr = que.front();
            que.pop();
            --count;
            //cout<<"visiting = "<<curr.first<< " state= "<<curr.second<<endl;
            
            if(curr.second == endState)
                return cost;
            
            for(auto nei: graph[curr.first])
            {
                int state = curr.second | (1 << nei);
                int hash = (1<<(nei+12)) | state; 
                pi p{nei, state };
                //cout<<p.first<<"  "<<p.second<< " hash="<<hash<< endl;
                
                if(visited.insert(hash).second)
                {
                    //cout<<"push "<<p.first<<endl;
                    que.push(p);
                }
            }
            
        }
        
        return -1;
        
    }
};