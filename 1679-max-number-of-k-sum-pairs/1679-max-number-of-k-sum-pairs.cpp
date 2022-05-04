class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        multiset<int> ms;
        int result=0;
        for(int n:nums)
        {
            auto it = ms.find(k-n);
            if(it != ms.end())
            {
                ms.erase(it);
                ++result;
            }
            else
                ms.insert(n);
        }
        return result;
    }
};