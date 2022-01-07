class Solution {
public:
    bool containsDuplicate1(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<nums.size()-1;++i)
            if(nums[i]==nums[i+1])
                return true;
        return false;
    }
    
    bool containsDuplicate2(vector<int>& nums) {
        unordered_set<int> seen;
        
        for(auto&  n:nums)
        {
            if(seen.count(n))
                return true;
            seen.insert(n);
        }   
        return false;
    }
    
    bool containsDuplicate(vector<int>& nums) {
        return set<int>(nums.begin(), nums.end()).size() < nums.size();
    }
};