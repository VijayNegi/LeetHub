class SmallestInfiniteSet {
    set<int> exclude;
public:
    SmallestInfiniteSet() {
        
    }
    
    int popSmallest() {
        int val = 0;
        if(exclude.empty()){
            val = 1;
            exclude.insert(1);
        }
        else{
            int pre=0;
            for(auto& k:exclude){
                if(k!=pre+1){
                    break;
                }
                pre=k;
            }
            val = pre+1;
            exclude.insert(val);
        }
        return val;
    }
    
    void addBack(int num) {
        exclude.erase(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */