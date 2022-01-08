class Solution {
public:
    // nlogn
    vector<int> topKFrequent1(vector<int>& nums, int k) {
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
    // nlogk
    vector<int> topKFrequent2(vector<int>& nums, int k) {
        unordered_map<int,int> count;
        for(auto& n:nums)
            count[n]++;
        function<bool(int,int)> cmp = [&](int a,int b){ if(count[a]>count[b])
                                                  return true;
                                                 return false; };
        priority_queue<int,vector<int>, decltype(cmp)> q(cmp);
        
        for(auto& [n,c]:count)
        {
            q.push(n);
            if(q.size()>k)
                q.pop();
        }
        
        vector<int> result;
        while(!q.empty())
        {
            result.push_back(q.top());
            q.pop();
        }
        
        return result;
    }
    // O(n)
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> count;
        for(auto& n:nums)
            count[n]++;
        
        unordered_map<int,vector<int>> freq;
        
        for(auto& [n,c]:count)
        {
            freq[c].push_back(n);
        }
        vector<int> result;
        for(int i=nums.size() ;i>0;--i)
        {
            if(freq.count(i))
            {
                result.insert(result.end(),begin(freq[i]),end(freq[i]));
                if(result.size()>=k)
                    break;
            }
        }
        
        return result;
    }
    
};