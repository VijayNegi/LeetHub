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
            if(mod[m]>result)
                id = idx[m];
            else if(mod[m]>=result){
                id = min(id,idx[m]);
            }
            result = max(result,mod[m]);

        }
        return id;
    }
};