class Solution {
public:

    bool carPooling(vector<vector<int>> trips, int capacity) {
        int n = trips.size();
        sort(begin(trips),end(trips), [](const vector<int>& a,const vector<int>& b) { if(a[1] < b[1]) return true; return false; } );  //using <= is throwing an exception for larger test cases
        
        
        auto cmp = [](pair<int,int>& left,pair<int,int>& right) { if(left.first > right.first) return true; return false; };
        priority_queue<pair<int,int>, std::vector<pair<int,int>>, decltype(cmp)> q(cmp);
        int curr_cap = capacity;
        
        for(auto& t: trips)
        {
            while(!q.empty())
            {
                auto& t1 =  q.top();
                if(t1.first <= t[1])
                {
                    curr_cap += t1.second;
                    q.pop();
                }
                else
                    break;
            }
            if(t[0] > curr_cap )
                return false;
            
            curr_cap -= t[0];
            q.push({t[2],t[0]});
            
        }
  
        return true;
    }
    
    bool carPooling1(vector<vector<int>>& trips, int capacity) {
        int n = trips.size();
        
        vector<int> sorted(n,0);
        iota(sorted.begin(),sorted.end(),0);
        
        sort(begin(sorted),end(sorted),[&](const int a,const int b){ if(trips[a][1] <= trips[b][1]) return true; return false;});
        
        //sort(begin(trips),end(trips), [](const vector<int>& a,const vector<int>& b) { if(a[1] <= b[1]) return true; return false; } );
        
        //auto cmp = [](pair<int,int>& left,pair<int,int>& right) { if(left.first > right.first) return true; return false; };
        auto cmp = [&](int left,int right) { if(trips[left][2] > trips[right][2]) return true; return false; };
        
        priority_queue<int, std::vector<int>, decltype(cmp)> q(cmp);
        int curr_cap = capacity;
        
        
        for(int i=0;i<n;++i)
        {
            auto& t = trips[i];
            while(!q.empty())
            {
                auto& t1 =  q.top();
                if(trips[t1][2] <= t[1])
                {
                    curr_cap += trips[t1][0];
                    q.pop();
                }
                else
                    break;
            }
            if(t[0] > curr_cap )
                return false;
            
            curr_cap -= t[0];
            q.push(i);
        }
        
        return true;
    }
};