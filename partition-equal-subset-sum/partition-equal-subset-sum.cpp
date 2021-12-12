class Solution {
public:
    //backtrack: TLE
    bool canPartition1(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int n:nums)
            sum+=n;
        sum /=2;
        
        function<bool(int,int)> makesum = [&](int idx,int sum3)
        {   
            if(sum3 == sum)
                return true;
            if(sum3 > sum || idx==n)
                return false;
            
            if(makesum(idx+1,sum3+nums[idx]))
               return true;
            return makesum(idx+1,sum3);
        };
        
        return makesum(0,0);
    }
     bool canPartition(vector<int>& nums) {
        int n = nums.size();
         int m = 0;
         int sum = 0;
         for(auto i:nums)
         {
             sum += i;
             m = max(i,m);
         }
         if( (sum & 1) || m>(sum/2))
             return false;
         sum /=2;
         vector<bool> target(sum+1,false);
         target[0] = true;
         for(auto a:nums)
         {
             for(int i=sum;i>=a;--i)
             {
                 target[i] = target[i] || target[i-a];
             }
         }
         return target[sum];
     }
};