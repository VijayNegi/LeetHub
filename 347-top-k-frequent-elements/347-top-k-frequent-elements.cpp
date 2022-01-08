class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> count;
        
        for(auto& n:nums)
            count[n]++;
        function<bool(int,int)> cmp = [&](int a,int b){ if(count[a]<count[b])
                                                  return true;
                                                 return false; };
        priority_queue<int,vector<int>, decltype(cmp)> q(cmp);
        
        for(auto& [n,c]:count)
        {
            q.push(n);
        }
        
        vector<int> result;
        while(k--)
        {
            result.push_back(q.top());
            q.pop();
        }
        
        return result;
        
    }
};