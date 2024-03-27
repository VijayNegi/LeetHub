class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        
        int result=0;
        int start=0;
        int product=1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>=k)
            {
                // reset
                start = i+1;
                product = 1;
                
            }
            else
            {
                product *= nums[i];
                while(product >= k)
                {
                    // remove the elements from the start of subarray
                    product /= nums[start];
                    start++;
                }
                
                result += i-start + 1;
            }
        }
        
        return result;
    }
};