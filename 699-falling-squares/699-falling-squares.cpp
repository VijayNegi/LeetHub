struct stree {
    stree *left,*right;
    int low,high;
    int height;
    stree(int l,int h,int newh) {
        low = l;
        high = h;
        height=newh;
        left = right= nullptr;
    }
    int get(int l,int h){
        if(h<low || l>high)
            return 0;
        if(low>=l && high<=h) {
            return height;
        }
        int mid = low + (high-low)/2;
        if(!left)
            return height;
        if(h <= mid)
            return left->get(l,h);
        else if(l > mid)
            return right->get(l,h);
        
        return max( left->get(l,h), right->get(l,h));    
    }
    void update(int l,int h,int newh) {
        if(h<low || l>high)
            return ;
        if(low>=l && high<=h) {
            height = newh;
            if(left){
                left->update(l,h,newh);
                right->update(l,h,newh);
            }
            return;
        }
        int mid = low + (high-low)/2;
        if(!left) {
            left = new stree(low,mid,height);
            right = new stree(mid+1,high,height);
        }
        if(h <= mid)
            left->update(l,h,newh);
        else if(l > mid)
            right->update(l,h,newh);
        else {
            left->update(l,h,newh);
            right->update(l,h,newh);
        }
        height  = max(height, max(left->height,right->height));
        return;
    }
};
class Solution {
    
public:
    // self segment tree solution
    vector<int> fallingSquares1(vector<vector<int>>& positions) {
        stree tree(1,1e8,0);
        int maxheight = 0;
        vector<int> result;
        for(auto b:positions){
            int base = tree.get(b[0],b[0]+b[1]-1);
            tree.update(b[0],b[0]+b[1]-1,base+b[1]);
            maxheight = max(maxheight,base+b[1]);
            result.push_back(maxheight);
        }
        return result;
    }
    // map solution without coordinate-compression
    // same as line-sweep
    //https://leetcode.com/problems/falling-squares/discuss/108783/c%2B%2B-map-based-short-solution
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        map<int,int> mp = {{0,0}};
        int curr=0;
        vector<int> res;
        for(auto b:positions){
            int l = b[0],r = b[0]+b[1],h = b[1];
            auto it_i = mp.upper_bound(l);  // upper as we have a min sentry entry
            auto it_j = mp.lower_bound(r);  // match or upper 
            int tmp = it_j->first == r? it_j->second : prev(it_j)->second; // height after this box end
            int maxh=0;
            for(auto i=prev(it_i);i!=it_j;++i) {
                maxh = max(maxh,i->second);
            }
            mp.erase(it_i,it_j);      //erase range
            mp[l] = h+maxh;           // new left bound
            mp[r] = tmp;              // new right bound
            curr = max(curr, mp[l]);
            res.push_back(curr);
        }
        return res;
    }
};