class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;++i){
            if(nums[i]>0 && nums[i]<=n){
                int idx = nums[i]-1;
                if(nums[i] != nums[idx]){
                    swap(nums[i],nums[idx]);
                    if(idx > i)
                        --i;
                }
            }
        }
        for(int i=1;i<=n;++i){
            //cout<<nums[i-1]<<" ";
            if(nums[i-1]!=i)
               return i;
        }
        return n+1;
    }
};