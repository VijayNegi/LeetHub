class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size()-1;
        function<int(int,int)> canWin = [&](int l,int r){
            if(l==r){
                return nums[l];
            }
            int diff = 0;
            int diff1 = nums[r] - canWin(l,r-1);
            int diff2 = nums[l] - canWin(l+1,r);
            diff = max(diff1,diff2);
            return diff;
        };
        return canWin(0,n)>=0;
    }
};