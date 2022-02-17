class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        uint32_t count[2001] = {0};
        
        for(auto a:arr)
            count[a+1000]++;
        
        unordered_map<int,int> occ_seen;
        for(int i=0;i<2001;++i)
        {
            if(count[i]>0)
            {
                if(count[i] > 0 && occ_seen[count[i]])
                    return false;
                occ_seen[count[i]]++;
            }
        }
        return true;
    }
};