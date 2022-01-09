class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int maxs = 0;
        int totals = 0;
        int n = nums.size();
        int totalOne = 0;
        for(auto k:nums)
            if(k==1)
                ++totalOne;
        
        if(totalOne>=n-1)
            return 0;
        
        int tempone = 0;
        
        int i=0;
        while(i<totalOne)
            if(nums[i++]) ++tempone;
        
        int maxones=tempone;
        for(;i<(totalOne+n);++i)
        {
            int end = i%n;
            int st = (i-totalOne)%n;
            
            if(nums[end]==1)
                ++tempone;
            if(nums[st]==1)
                --tempone;
            maxones = max(maxones,tempone);
    
        }
        
        return totalOne - maxones;
    }
};