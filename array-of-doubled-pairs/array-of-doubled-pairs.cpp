class Solution {
public:
    bool canReorderDoubled1(vector<int>& arr) {
        unordered_map<int,int> nummap;
        for(auto a:arr)
            nummap[a]++;
        
        sort(arr.begin(),arr.end(),[](int i,int j){ return abs(i)<abs(j);});
        
        for(auto a:arr)
        {
            if(nummap[a]> nummap[a*2])
                return false;
            nummap[2*a] -= nummap[a];
        }
        return true;
    }
    bool canReorderDoubled(vector<int>& A) {
        unordered_map<int, int> c;
        for (int a : A) c[a]++;
        vector<int> keys;
        for (auto it : c)
            keys.push_back(it.first);
        sort(keys.begin(), keys.end(), [](int i, int j) {return abs(i) < abs(j);});
        for (int x : keys) {
            if (c[x] > c[2 * x])
                return false;
            c[2 * x] -= c[x];
        }
        return true;
    }
};