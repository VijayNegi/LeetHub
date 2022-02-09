class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        
        int n = nums.size();
        int l=0,r=1;
        int result = 0;
        while(r<n)
        {
            int diff = nums[r]-nums[l];
            
            if(diff == k)
            {
                ++result;
                
                ++l;
                ++r;
                while(r<n && nums[r]== nums[r-1])
                    ++r;
            }
            else if(diff < k)
            {
                ++r;
            }
            else
            {
                ++l;
            }
            
            if(l==r)
                ++r;
            
        }
        return result;
    }
};