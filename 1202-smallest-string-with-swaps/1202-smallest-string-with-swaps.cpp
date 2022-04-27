struct DSU
{
    vector<int> parent;
    int n;
    DSU(int s):parent(s,0),n(s)
    {
        iota(begin(parent),end(parent),0);
    }
    int find(int idx)
    {
        if(idx == parent[idx])
            return idx;
        return parent[idx] = find(parent[idx]);
    }
    
    void merge(int idx1, int idx2)
    {
        int pidx1 = find(idx1);
        int pidx2 = find(idx2);
        
        if(pidx1 == pidx2)
            return;
        parent[pidx2] = pidx1;
    }
};

class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        DSU dset(n);
        for(auto v:pairs)
            dset.merge(v[0],v[1]);
        unordered_map<int,multiset<char>> gmap;
        for(int i=0;i<n;++i)
        {
            gmap[dset.find(i)].insert(s[i]);
        }
        string result;
        
        for(int i=0;i<n;++i)
        {
            auto it = gmap[dset.find(i)].begin();
            result += *it;
            gmap[dset.find(i)].erase(it);
        }
        return result;
    }
};