class Solution {
public:
    int search(vector<int>& nums, int target) {
        auto it = lower_bound(begin(nums),end(nums),target);
        if(it != nums.end())
        {
            if(*it==target)
                return distance(nums.begin(),it);
        }
         return -1;   
    }
};