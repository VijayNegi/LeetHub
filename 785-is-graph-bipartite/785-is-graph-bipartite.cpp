class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        bool curr = false;
        int n = graph.size();
        vector<int> visited(n,false);
        vector<int> colour(n,false);
        for(int i=0;i<n;++i)
        {
            if(visited[i])  continue;
            queue<int> q;
            q.push(i);
            queue<int> p;
            while(!q.empty())
            {
                int k = q.front();
                q.pop();
                visited[k] = true;
                colour[k] = curr;
                for(auto t:graph[k])
                {
                    if(visited[t] && colour[t] == curr)
                        return false;
                    else if(!visited[t])
                        p.push(t);
                }
                if(q.empty())
                {
                    swap(p,q);
                    curr = !curr;
                }
            }
        }
        return true;
        
    }
};