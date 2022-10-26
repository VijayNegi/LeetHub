class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_set<int> seen;
        long sum=0;
        long pre=0;
        for(auto& n:nums){
            sum += n;
            sum %= k;
            if(seen.count(sum))
                return true;
            seen.insert(pre);
            pre = sum;
        }
        return false;
    }
};