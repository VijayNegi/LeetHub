class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        auto cmp = [&](int l,int r) {
            int al = abs(l-x);
            int ar = abs(r-x);
            if(al == ar) return l<r;
            return ar>al;
        };
        priority_queue<int,vector<int>,decltype(cmp)> pq(cmp);
        
        for(auto& p:arr){
            pq.push(p);
            if(pq.size()>k)
                pq.pop();
        }
        vector<int> result;
        while(pq.size()) {
            result.push_back(pq.top());
            pq.pop();
        }
        sort(begin(result),end(result));
        return result;
    }
};