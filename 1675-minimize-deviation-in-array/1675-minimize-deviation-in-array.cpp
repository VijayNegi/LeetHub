using idVal = pair<int,int>;
class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int> pq;
        int min_n = INT_MAX;
        for(auto n:nums)
        {
           if(n%2==1)
               n*=2;
            min_n = min(min_n,n);
            pq.push(n);
        }
        int res = INT_MAX;
        
        while(pq.top()%2==0)
        {
            int m = pq.top();
            pq.pop();
            res = min(res, m-min_n);
            min_n = min(min_n, m / 2);
            pq.push(m/2);
        }
        return min(res,  pq.top()-min_n);
    }
};