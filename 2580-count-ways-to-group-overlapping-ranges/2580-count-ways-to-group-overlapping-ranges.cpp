const int mod = 1e9+7;
class Solution {
public:
    int countWays(vector<vector<int>>& ranges) {
        map<int,int> irange;  // end - start
        sort(begin(ranges),end(ranges),[](vector<int>& l,vector<int>& r){ if(l[1]==r[1]) return true; return l[1]>r[1];});
        for(auto& r:ranges){
            auto it = irange.lower_bound(r[0]);
            if(it != irange.end() && it->second <= r[1]){
                it->second = min(r[0],it->second);
            }
            else
                irange[r[1]] = r[0];
        }
        int k = irange.size(); // unique sets after merge
        long long res=1;
        // now find sum of series nC0+nC1 .... + nCn = 2^n
        while(k>=10){
            res *= pow(2,10);
            res %= mod;
            k-=10;
        }
        res *= pow(2,k);
        res %= mod;
        return res;
    }
};