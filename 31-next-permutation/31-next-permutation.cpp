class Solution {
public:
    void nextPermutation1(vector<int>& nums) {
        int n = nums.size();
        int i=n-2;
        for(i=n-2;i>=0;--i)
        {
            if(nums[i]<nums[i+1])
            {
                int j=i+1;
                for(;j<n;++j)
                    if(nums[j]<=nums[i])
                        break;
                swap(nums[i],nums[j-1]);
                break;
            }
        }
        reverse(begin(nums)+i+1,end(nums));
    }
    void nextPermutation(vector<int>& nums) {
      std::next_permutation(nums.begin(), nums.end());
    }

};