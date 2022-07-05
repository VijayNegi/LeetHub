struct DSU {
    vector<int> parent;
    vector<int> size;
    int maxSize=1;
    DSU(int n):parent(n),size(n,1) {
        iota(parent.begin(),parent.end(),0);
    }
    
    int getParent(int idx) {
        if(parent[idx]==idx)
            return idx;
        return parent[idx] = getParent(parent[idx]);
    }
    
    void merge(int idx1,int idx2) {
        int p1 = getParent(idx1);
        int p2 = getParent(idx2);
        if(p1==p2)
            return;
        parent[p2] = p1;
        size[p1] += size[p2];
        size[p2]=0;
        if(size[p1]>maxSize)
            maxSize = size[p1];
    }
};
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> idx;
        int n= nums.size();
        if(n<2)
            return n;
        for(int i=0;i<n;++i) {
            //if(idx.count[])
            idx[nums[i]] = i;
        }
        DSU numset(n);
        for(int i=0;i<n;++i) {
            if(idx.count(nums[i]+1)>0) {
                numset.merge(idx[nums[i]],idx[nums[i]+1]);
            }
            if(idx.count(nums[i]-1)>0) {
                numset.merge(idx[nums[i]],idx[nums[i]-1]);
            }
        }
        return numset.maxSize;
    }
};