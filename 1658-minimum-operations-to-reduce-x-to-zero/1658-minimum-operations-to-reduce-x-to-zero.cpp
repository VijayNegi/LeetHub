class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        unordered_map<int,int> pre;
        int sum = nums[0];
        pre[sum] = 1;
        for(int i=1;i<n;++i) {
            sum += nums[i];
            pre[sum] = i+1;
        }
        sum = 0;
        int result = n+1;
        if(pre[x])
            result = pre[x];
        for(int i=n-1;i>=0;--i) {
            sum += nums[i];
            if(sum==x)
                result = min(result, n-i);
            if(pre[x-sum])
                result = min(result,pre[x-sum] + n-i);
        }
        if(result == n+1)
            return -1;
        return result;
        
    }
};