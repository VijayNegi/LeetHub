class Solution {
public:
    // count sort and hashmap
    bool uniqueOccurrences1(vector<int>& arr) {
        uint32_t count[2001] = {0};
        for(auto a:arr)
            count[a+1000]++;
        unordered_map<int,int> occ_seen;
        for(int i=0;i<2001;++i)
        {
            if(count[i]>0)
            {
                if(occ_seen[count[i]])  return false;
                occ_seen[count[i]]++;
            }
        }
        return true;
    }
    // map and set
    bool uniqueOccurrences(vector<int>& arr) 
    {
      unordered_map<int, int> m;
      unordered_set<int> s;
      for (auto n : arr) ++m[n];
      for (auto& p : m) s.insert(p.second);
      return m.size() == s.size();
    }
};