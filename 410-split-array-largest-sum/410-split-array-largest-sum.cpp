class Solution {
public:
    // top down dp 296ms
    int splitArray1(vector<int>& nums, int m) {
        int n = nums.size();
        vector<vector<int>> mem(n+1,vector(m+1,-1));
        function<int(int,int,int)> dfs = [&](int idx,int split,int sum)
        {
            if(mem[idx][split] != -1)
                return mem[idx][split];
            if(split==1)
                return mem[idx][split] = sum;
            int s = 0;
            int result = INT_MAX;
            for(int i=idx;i<=(n-split);++i)
            {
                s += nums[i];
                int res = dfs(i+1,split -1,sum-s);
                result = min(result,max(res,s));
                if(s>result)
                    break;
            }
            return mem[idx][split] = result;
        };
        int sum = accumulate(begin(nums),end(nums),0);
        return dfs(0,m,sum);
    }
    
    // bottom up 
    
    int memo[1001][51];
    
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        
        // Store the prefix sum of nums array
        vector<int> prefixSum(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }
        
        for (int subarrayCount = 1; subarrayCount <= m; subarrayCount++) {
            for (int currIndex = 0; currIndex < n; currIndex++) {
               // Base Case: If there is only one subarray left, then all of the remaining numbers
               // must go in the current subarray. So return the sum of the remaining numbers.
                if (subarrayCount == 1) {
                    memo[currIndex][subarrayCount] = prefixSum[n] - prefixSum[currIndex];
                    continue;
                }

                // Otherwise, use the recurrence relation to determine the minimum largest subarray
                // sum between currIndex and the end of the array with subarrayCount subarray remaining.
                int minimumLargestSplitSum = INT_MAX;
                for (int i = currIndex; i <= n - subarrayCount; i++) {
                    // Store the sum of the first subarray.
                    int firstSplitSum = prefixSum[i + 1] - prefixSum[currIndex];

                    // Find the maximum subarray sum for the current first split.
                    int largestSplitSum = max(firstSplitSum, memo[i + 1][subarrayCount - 1]);

                    // Find the minimum among all possible combinations.
                    minimumLargestSplitSum = min(minimumLargestSplitSum, largestSplitSum);

                    if (firstSplitSum >= minimumLargestSplitSum) {
                        break;
                    }
                }

                memo[currIndex][subarrayCount] = minimumLargestSplitSum;
            }
        }
        
        return memo[0][m];
    }
};