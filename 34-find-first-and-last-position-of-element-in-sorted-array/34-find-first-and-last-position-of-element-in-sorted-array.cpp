class Solution {
public:
    // using std binary search
    vector<int> searchRange1(vector<int>& nums, int target) {
        auto it = upper_bound(nums.begin(),nums.end(),target-1);
        if(it== nums.end() || (*it!=target))
            return {-1,-1};
        auto it1 = lower_bound(nums.begin(),nums.end(),target+1);
        int start = distance(nums.begin(),it);
        int end = distance(nums.begin(),it1);
        return {start,end-1};
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        if(n==0)
            return {-1,-1};
        int l=0,r=n;
        while(l<r){
            int mid = l+(r-l)/2;
            if(nums[mid]<target)
                l=mid+1;
            else r = mid;
        }
        //++l;
        //cout<<"c";
        if(l==n || nums[l]!=target)
            return {-1,-1};
        int start = l;
        l=0,r=n;
        while(l<r){
            int mid = l+(r-l)/2;
            if(nums[mid]<= target)
                l=mid+1;
            else r = mid;
        }
        --l;
        return {start,l};
        
    }
};