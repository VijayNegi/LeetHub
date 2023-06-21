class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        // Sort integers by values.
        int n = nums.size();
        vector<vector<int>> numsAndCost(n,vector(2,0));
        for (int i = 0; i < n; ++i) {
            numsAndCost[i][0] = nums[i];
            numsAndCost[i][1] = cost[i];
        }
        sort(begin(numsAndCost), end(numsAndCost));

        // Get the prefix sum array of the costs.
        vector<long> prefixCost(n,0);
        prefixCost[0] = numsAndCost[0][1];
        for (int i = 1; i < n; ++i)
            prefixCost[i] = numsAndCost[i][1] + prefixCost[i - 1];

        // Then we try every integer nums[i] and make every element equals nums[i],
        // Start with nums[0]
        long totalCost = 0l;
        for (int i = 1; i < n; ++i)
            totalCost += 1l * numsAndCost[i][1] * (numsAndCost[i][0] - numsAndCost[0][0]);
        long answer = totalCost;
        
        // Then we try nums[1], nums[2] and so on. The cost difference is made by the change of
        // two parts: 1. prefix sum of costs. 2. suffix sum of costs. 
        // During the iteration, record the minimum cost we have met.
        for (int i = 1; i < n; ++i) {
            int gap = numsAndCost[i][0] - numsAndCost[i - 1][0];
            totalCost += 1l * prefixCost[i - 1] * gap;
            totalCost -= 1l * (prefixCost[n - 1] - prefixCost[i - 1]) * gap;
            answer = min(answer, totalCost);
        }
        
        return answer;
    }
};