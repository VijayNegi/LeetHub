class Solution {
public:
    // using property xor: n ^ n is null, so we xor all numbers and array, missing n will be left.
    int missingNumber(vector<int>& nums) {
        int res = 0;
        int i=0;
        for(auto n:nums)
        {
            res = (res^n)^i++;
        }
        
        res = res^i;
        
        return res;
    }
};