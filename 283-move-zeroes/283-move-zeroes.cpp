class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int d,n,count;
        d=count=0;
        n = nums.size();
        for(int i=0;i<n;++i)
        {
            if(nums[i]!=0)
                nums[d++] = nums[i];
            else
                ++count;
        }
        for(int i=n-1;i>=n-count;--i)
            nums[i] = 0;
    }
};