#if 0
// segment-tree, 54 / 54 Test case passed but TLE
struct stree{
    int low,high;
    stree *left,*right;
    bool tracked;
    stree(int rlow,int rhigh){
        low = rlow;
        high = rhigh;
        left = right = nullptr;
        tracked = false;
    }
    void add(int rlow,int rhigh) {
        if(rlow> high || rhigh < low)
            return;
        if(rlow<=low && rhigh>=high){
            tracked = true;
            if(left){
                left->add(rlow,rhigh);
                right->add(rlow,rhigh);
            }
            return;
        }
        if(tracked)
            return;
        int mid = low + (high-low)/2;
        if(!left) {
            left = new stree(low,mid);
            right = new stree(mid+1,high);
        }
        left->add(rlow,rhigh);
        right->add(rlow,rhigh);
        tracked = right->tracked && left->tracked;
        return;
    }
    bool query(int rlow, int rhigh){
        if(rlow> high || rhigh < low)
            return false;
        if((rlow<=low && rhigh>=high) || tracked || !left){
            return tracked;
        }
        int mid = low + (high-low)/2;
        if(mid >= rhigh)
            return left->query(rlow,rhigh);
        else if(mid<rlow)
            return right->query(rlow,rhigh);
        else 
            return left->query(rlow,rhigh) && right->query(rlow,rhigh);
        return false;
    }
    void remove(int rlow,int rhigh){
         if(rlow> high || rhigh < low)
            return;
        int mid = low + (high-low)/2;
        
        if((rlow<=low && rhigh>=high)){
            tracked = false;
            if(left) {
                left->remove(rlow,rhigh);
                right->remove(rlow,rhigh);
            }
            return;
        }
        if(!tracked && !left)
            return;
        if(!left) {
            left = new stree(low,mid);
            right = new stree(mid+1,high);
            left->tracked = tracked;
            right->tracked = tracked;
        }
            
        if(mid >= rhigh)
            left->remove(rlow,rhigh);
        else if(mid<rlow)
            right->remove(rlow,rhigh);
        else {
            left->remove(rlow,rhigh);
            right->remove(rlow,rhigh);
        }
        tracked = false;
    }
};
class RangeModule {
    stree tree;
public:
    RangeModule():tree(1,1e9) {
        
    }
    
    void addRange(int left, int right) {
        tree.add(left,right-1);
        
    }
    
    bool queryRange(int left, int right) {
        return tree.query(left,right-1);
    }
    
    void removeRange(int left, int right) {
        tree.remove(left,right-1);
    }
};
#endif
// https://leetcode.com/problems/range-module/discuss/108912/C%2B%2B-vector-O(n)-and-map-O(logn)-compare-two-solutions
class RangeModule {
public:
    void addRange(int left, int right) {
        auto l = invals.upper_bound(left), r = invals.upper_bound(right); 
        if (l != invals.begin()) {
            l--;
            if (l->second < left) l++;
        }
        if (l != r) {
            left = min(left, l->first);
            right = max(right, (--r)->second);
            invals.erase(l,++r);
        }
        invals[left] = right;
    }
    
    bool queryRange(int left, int right) {
        auto it = invals.upper_bound(left);
        if (it == invals.begin() || (--it)->second < right) return false;
        return true;
    }
    
    void removeRange(int left, int right) {
        auto l = invals.upper_bound(left), r = invals.upper_bound(right); 
        if (l != invals.begin()) {
            l--;
            if (l->second < left) l++;
        }
        if (l == r) return;
        int l1 = min(left, l->first), r1 = max(right, (--r)->second);
        invals.erase(l, ++r);
        if (l1 < left) invals[l1] = left;
        if (r1 > right) invals[right] = r1;
    }
private:
    map<int, int> invals;
};
/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */