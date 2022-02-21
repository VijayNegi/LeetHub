class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=1;
        int maj = nums[0];
        for(int i=1;i<nums.size();++i)
        {
            if(count==0)
            {
                maj = nums[i];
                ++count;
            }
            else if(maj != nums[i])
                --count;   
            else 
                ++count;
        }
        return maj;
    }
};