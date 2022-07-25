class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto it = upper_bound(nums.begin(),nums.end(),target-1);
        if(it== nums.end() || (*it!=target))
            return {-1,-1};
        auto it1 = lower_bound(nums.begin(),nums.end(),target+1);
        int start = distance(nums.begin(),it);
        int end = distance(nums.begin(),it1);
        return {start,end-1};
    }
};