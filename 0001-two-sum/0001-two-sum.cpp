class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> seen;
        for(int i=0;i<nums.size();++i){
            if(seen[target - nums[i]])
                return {seen[target - nums[i]]-1,i};
            seen[nums[i]] = i+1;
        }
        return {0,0};
    }
};