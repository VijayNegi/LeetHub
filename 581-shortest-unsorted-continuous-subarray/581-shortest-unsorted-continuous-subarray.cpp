class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        if(n==1)
            return 0;
         int l=n-1,r=0;
        int low = nums[n-1];
        int high = nums[0];
        
        for(int i=1;i<n;++i)
        {
            if(nums[i]>=high)
                high = nums[i];
            else
                r=i;
        }
        
        for(int i=n-2;i>=0;--i)
        {
            if(nums[i]<=low)
                low = nums[i];
            else
                l=i;
        }
        //cout<<l<<" "<<r<<endl;
        if(l<r)
            return r-l+1;
        return 0;
    }
};