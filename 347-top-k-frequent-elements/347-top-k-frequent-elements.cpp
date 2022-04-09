class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(auto n:nums)
            mp[n]++;
        vector<int> t;
        for(auto it:mp)
            t.push_back(it.first);
        if(k==t.size())
            return t;
        int l=0,r=t.size()-1;
        while(true)
        {
            int p = partition(t,l,r,mp);
            if(p==k-1)
                break;
            else if(p>k-1)
                r=p-1;
            else
                l=p+1;
        }
        t.resize(k);
        return t;
        
    }
    
    int partition(vector<int>& v,int l, int r,unordered_map<int,int>& mp)
    {
        int pivot = l;
        ++l;
        while(l<=r)
        {
            if(mp[v[l]]< mp[v[pivot]] && mp[v[r]] > mp[v[pivot]])
                swap(v[l++],v[r--]);
            else if(mp[v[l]] >= mp[v[pivot]])
                ++l;
            else if(mp[v[r]] <= mp[v[pivot]])
                --r;
        }
        swap(v[r],v[pivot]);
        return r;
    }
};