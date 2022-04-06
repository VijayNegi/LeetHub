class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        multiset<int,greater<int>> s;
        
        for(auto& n:nums)
        {
            s.insert(n);
            if(s.size()>k)
            {
                auto it = s.begin();
                std::advance(it,k);
                s.erase(it);
            }
                
        }
        auto it = s.begin();
        std::advance(it,k-1);
        return *(it);
    }
};