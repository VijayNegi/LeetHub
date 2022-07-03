class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if(n==1 || (n==2 && nums[0]!=nums[1]) )
            return n;
        if(n==2 && nums[0]==nums[1])
            return 1;
        vector<int> seq;
        seq.push_back(nums[0]);
        int i=1;
        for(;i<n;++i)
            if(nums[i]!=seq.back())
                break;
        if(i==n)
            return 1;
        seq.push_back(nums[i]);
        bool up = nums[i] > nums[0];
        for(;i<n;++i) {
            if(up && nums[i] < seq.back()) {
                //cout<<"up:"<<nums[i]<<endl;
                seq.push_back(nums[i]);
                up = !up;
            }
            else if(!up && nums[i] > seq.back()) {
                //cout<<"dn:"<<nums[i]<<endl;
                seq.push_back(nums[i]);
                up = !up;
            }
            else 
                seq.back() = nums[i];
        }
        return seq.size();
    }
};