class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        //priority_queue<int> pq;
        vector<int> v;
        for(auto& i:nums) {
            auto it = lower_bound(v.begin(),v.end(),i);
            if(it!=v.end())
                *it = i;
            else
                v.push_back(i);
            if(v.size()>=3)
                return true;
        }
        return false;
    }
};