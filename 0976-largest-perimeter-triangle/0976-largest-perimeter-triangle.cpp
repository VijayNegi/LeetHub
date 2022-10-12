class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        sort(begin(nums),end(nums),greater<>());
        //int result=0;
        for(int i=0;i<n-2;++i) {
            if(nums[i+1]+nums[i+2] > nums[i])
                return nums[i]+nums[i+1]+nums[i+2];
        }
        return 0;
    }
};