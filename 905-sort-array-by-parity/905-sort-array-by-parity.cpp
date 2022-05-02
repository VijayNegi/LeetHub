class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        auto cmp = [](int l,int r){if ((l & 1) < (r&1))
                                   return true;
                                   return false;};
        sort(begin(nums),end(nums),cmp);
        return nums;
    }
};