class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        unordered_set<int> s;
        int dup=0;
        for(auto i:nums){
            sum+=i;
            auto r = s.insert(i);
            if(!r.second)
                dup = i;
        }
        int actual = n*(n+1)/2;
        vector<int> result{dup, dup + actual-sum};
        return result;
    }
};