class KthLargest {
    int k;
    multiset<int,less<int>> s;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(auto& n:nums)
        {
            s.insert(n);
            if(s.size()>k)
                s.erase(s.begin());
        }
    }
    
    int add(int val) {
        s.insert(val);
        if(s.size()>k)
            s.erase(s.begin());
        return *(s.begin());
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */