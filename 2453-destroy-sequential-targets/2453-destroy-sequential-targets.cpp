class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        
        unordered_map<int,int> mod;
        unordered_map<int,int> idx;
        int result=0;
        int id=INT_MAX;
        for(auto& n:nums){
            int m = n%space;
            mod[m]++;
            if(mod[m]==1){
                idx[m]=n;
            }
            else{
                idx[m] = min(idx[m],n);
            }
        }
        for(auto& m:mod){
            if(m.second > result )
                id = idx[m.first];
            else if(m.second >=result)
                 id = min(id,idx[m.first]);
            result = max(result,m.second);
        }
        return id;
    }
};