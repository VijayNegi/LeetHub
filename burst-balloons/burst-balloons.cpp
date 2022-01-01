class Solution {
public:
    int pop(vector<int>& nums, int l,int r)
    {
        //cout<<"l="<<l<<" r="<<r<<endl;
        if(r<=l || r-l == 1) // no balloon to pop
            return 0;
        if(r-l == 2) // one balloon to pop
        {
            return nums[l]*nums[l+1]*nums[r];
        }
        
        // otherwise find biggest ballon in this range and burst it last,
        int mIdx = l+1;
        for(int i = l+2;i<r;++i)
        {
            if(nums[i]>nums[mIdx])
                mIdx = i;
        }
        //cout<<"max="<<nums[mIdx]<<endl;
        
        int res = pop(nums,l,mIdx);
        res += pop(nums,mIdx,r);
        
        res += nums[l]*nums[mIdx]*nums[r];
        return res;
        
    }
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        int res=0;
        if(n==1)
        {
            return nums[0];
        }
        else if(n==2)
        {
            res = nums[0]*nums[1];
            res += (nums[0]>nums[1])? nums[0]: nums[1];
            return res;
        }
        else if(n==3)
        {
            res = nums[0]*nums[1]*nums[2];
            res += nums[0]*nums[2];
            res += (nums[0]>nums[2])? nums[0]: nums[2];
            return res;
        }
        
        // res = pop(nums,0,n-1);
        // res += nums[0]*nums[n-1];
        // res += (nums[0]>nums[n-1])? nums[0]: nums[n-1];
        
        vector<int> nums1{1};
        nums1.insert(nums1.end(),nums.begin(),nums.end());
        nums1.push_back(1);
        //cout<<nums1.size()<<endl;
        
        vector<vector<int>> dp(n+2,vector<int>(n+2,0));
        
        for(int k=2;k<n+2;++k)
        {
            for(int i= 0;i<n+2-k;++i)
            {
                int left = i;
                int right = i+k;
                for(int j=left+1;j<right;++j)
                {
                    dp[left][right] = max(dp[left][right], dp[left][j]+ dp[j][right] + nums1[left]*nums1[j]*nums1[right]);
                }
            }
        }
        
        
        return dp[0][n+1];
    }
};