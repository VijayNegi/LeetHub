class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        sort(begin(nums),end(nums));
        vector<int> res;
        int k=0;
        for(int i = 1; i<= nums.size();++i)
        {
            if(k>= nums.size() || nums[k] != i)
                res.push_back(i);
            while(k<nums.size() && nums[k] == i)
                ++k;
        }
        
        return res;
    }
};