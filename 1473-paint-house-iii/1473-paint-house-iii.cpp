class Solution {
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        int memo[100][100][21];
        // Maximum cost possible plus 1
        const int MAX_COST = 1000001;
        memset(memo, -1, sizeof(memo));
        function<int(int,int,int)> dfs = [&](int h,int k,int c) { // h-house no, k- neighbour count, c- previous house color
            if(h == m)
                return k == target? 0 : MAX_COST;
            if(k>target) 
                return MAX_COST;
            if(memo[h][k][c] != -1)
                return memo[h][k][c];
            int minCost = MAX_COST;
            if(houses[h]) {
                int newK = k + (houses[h] != c);
                minCost = dfs(h+1,newK,houses[h]);
            } else {
                for(int color=1;color<= n;++color) {
                    int newK = k + (color != c);
                    int currCost = cost[h][color-1] + dfs(h+1,newK,color);
                    minCost = min(minCost,currCost);
                }
            }
            return memo[h][k][c] = minCost;
        };
        int result = dfs(0,0,0);
        return result == MAX_COST? -1: result;
    }
};