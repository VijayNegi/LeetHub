class RandomizedSet {
    unordered_map<int,int> us;
    vector<int> num;
    default_random_engine eng;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(us.count(val)==1) return false;
        us[val] = num.size();
        num.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if(us.count(val)==0) return false;
        swap(num[us[val]],num[num.size()-1]);
        us[num[us[val]]] = us[val];
        us.erase(val);
        num.pop_back();
        return true;
    }
    
    int getRandom() {
        return num[ eng() % (num.size())];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */