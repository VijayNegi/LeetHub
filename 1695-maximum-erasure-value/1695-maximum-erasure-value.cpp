class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        vector<bool> hash(10001,false);
        int sum=0,l=0,r=0;
        int result=0;
        int n= nums.size();
        while(r<n) {
            if(!hash[nums[r]]) {
                hash[nums[r]] = true;
                sum += nums[r++];
                result = max(result,sum);
            }
            else {
                hash[nums[l]] = false;
                sum -= nums[l++];
            }
        }
        return result;
    }
};