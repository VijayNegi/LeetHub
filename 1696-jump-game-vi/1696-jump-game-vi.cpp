class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<pair<int,int>> pq;
        int sum = 0;
        for(int i=0;i<n;++i) {
            while(pq.size() && pq.top().second < i-k)
                pq.pop();
            if(pq.size())  {
                //cout<<pq.top().first<<" "<<pq.top().second<<"  ";
                int s = pq.top().first + nums[i];
                
                pq.push({s,i});
            }
            else {
                //cout<<"w"<<endl;
                pq.push({nums[i],i});
            }
        }
        while(pq.top().second != n-1)
            pq.pop();
        return pq.top().first;
    }
};