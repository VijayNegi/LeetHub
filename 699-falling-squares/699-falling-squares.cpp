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
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        stree tree(1,1e8,0);
        int maxheight = 0;
        vector<int> result;
        for(auto b:positions){
            //cout<<b[1]<<" ";
            int base = tree.get(b[0],b[0]+b[1]-1);
            //cout<<" get "<<base<<endl;
            tree.update(b[0],b[0]+b[1]-1,base+b[1]);
            maxheight = max(maxheight,base+b[1]);
            result.push_back(maxheight);
            //cout<< "end "<<b[1]<<endl;;
        }
        return result;
    }
};