class Solution {
public:
    // lis
    int maxEnvelopes(vector<vector<int>>& env) {
        sort(begin(env),end(env),[](vector<int>& l,vector<int>& r){
            if(l[0]==r[0])
                return l[1]>r[1];
            return l[0]<r[0];
        });
        
        vector<int> lis;
        for(auto& e:env){
            auto it = lower_bound(begin(lis),end(lis),e[1]);
            if(it == end(lis))
                lis.push_back(e[1]);
            else
                *it = e[1];
        }
        return lis.size();
    }
};