class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<pair<int,int>> pq;
        pq.push({nums[0],0});
        for(int i=1;i<n;++i) {
            while(pq.top().second < i-k) // no need to check size
                pq.pop();
            int s = pq.top().first + nums[i];
            pq.push({s,i}); 
        }
        while(pq.top().second != n-1)
            pq.pop();
        return pq.top().first;
    }
};