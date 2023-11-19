class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(begin(nums),end(nums));
        int n = nums.size()-1;
        int result=0;
        while(n>=0){
            int k = n;
            while(k>=0 && nums[k]==nums[n]) --k;
            //int count = n-k+1;
            if(k >=0)
                result += nums.size() - k-1;
            //cout<<result<<endl;
            n = k;
        }
        return result;
    }
};