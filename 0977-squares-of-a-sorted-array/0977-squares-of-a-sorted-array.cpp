class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int mabs = numeric_limits<int>::max();
        int idx = -1;
        int n = nums.size();
        for(int i=0;i<n;++i){
            if(mabs > nums[i]*nums[i]){
                mabs  = nums[i]*nums[i];
                idx = i;
            }
        }
        int l = idx-1;
        int r = idx;
        vector<int> result;
        while(l>=0 || r<n){
            int ll = numeric_limits<int>::max();
            int rr = numeric_limits<int>::max();
            if(l>=0)
                ll = nums[l]*nums[l];
            if(r<n)
                rr = nums[r]*nums[r];
            if(ll<=rr){
                result.push_back(ll);
                --l;
            }
            else{
                result.push_back(rr);
                ++r;
            }
        }
        return result;
    }
};