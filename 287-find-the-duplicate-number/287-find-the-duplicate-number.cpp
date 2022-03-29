class Solution {
public:
    // property of n natual numbers
    int findDuplicate(vector<int>& nums) {
        int ans = -1;
        
        for(auto& a:nums)
        {
            if(nums[abs(a)]<0)
            {
                ans = abs(a);
                break;
            }
            else
                nums[abs(a)] = -1* nums[abs(a)];
        }
        for(auto& a:nums)
            if(a<0)
                a = -1*a;
        
        return ans;
    }
};