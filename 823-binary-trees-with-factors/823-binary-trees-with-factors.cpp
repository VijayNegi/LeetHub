const int mod = 1e9+7;
class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        int n = arr.size();
        sort(begin(arr),end(arr));
        unordered_map<int,long> memo;
        long result = 0;
        for(auto& k:arr) {
           memo[k] = 1;
        }
        for(int i=0;i<n;++i) {
            for(int j=0;j<=i;++j) {
                long mul = (long)arr[i]*arr[j];
                if(mul>=INT_MAX)
                    continue;
                if(memo.count(mul)) {
                    int count = (memo[arr[i]]*memo[arr[j]])%mod;
                    if(arr[i]!=arr[j])
                        count = (2l * count)%mod;
                    memo[mul] = (memo[mul] + count) %mod;
                }
            }
        }
        for(auto& c:memo){
            result += c.second;
            result %=mod;
        }
        return result;
    }
};