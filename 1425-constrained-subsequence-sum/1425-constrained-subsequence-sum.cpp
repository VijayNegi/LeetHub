class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n+1,0);
        int sum=INT_MIN;
        // Using lambda to compare elements.
        auto cmp = [&](int left, int right) { return dp[left] < dp[right]; };
        std::priority_queue<int, std::vector<int>, decltype(cmp)> pq(cmp);
        
        for(int i=0;i<n;++i)
        {
            dp[i] = nums[i];
            if(!pq.empty())
            {
                while(pq.top()< i-k)
                    pq.pop();
                
                dp[i] = max(dp[i],dp[pq.top()]+nums[i]);
            }
            pq.push(i);
            sum = max(sum,dp[i]);
        }
        return sum;
    }
};