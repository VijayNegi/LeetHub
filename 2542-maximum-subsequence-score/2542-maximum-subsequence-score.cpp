class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int,int>> np;
        int n = nums1.size();
        for(int i=0;i<n;++i){
            np.push_back({nums2[i],nums1[i]});
        }
        sort(rbegin(np),rend(np));
        long long res=0, sum=0;

        priority_queue <int, vector<int>, greater<int>> pq; //min heap
        for (auto& [m, s] : np) {
            pq.emplace(s);
            sum += s;
            if (pq.size() > k) {
                sum -= pq.top();
                pq.pop();
            }
            if (pq.size() == k)
                res = max(res, sum * m);
        }
        return res;
    }
};