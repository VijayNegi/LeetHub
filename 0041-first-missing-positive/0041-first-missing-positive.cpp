class Solution {
public:
    // 63 ms
    int firstMissingPositive1(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;++i){
            if(nums[i]>0 && nums[i]<=n){
                int idx = nums[i]-1;
                if(nums[i] != nums[idx]){
                    swap(nums[i],nums[idx]);
                    if(idx > i) --i;
                }
            }
        }
        for(int i=1;i<=n;++i){
            if(nums[i-1]!=i) return i;
        }
        return n+1;
    }
    //more clean
    int firstMissingPositive(vector<int>& A)
    {
        int n = A.size();
        for(int i = 0; i < n; ++ i)
            while(A[i] > 0 && A[i] <= n && A[A[i] - 1] != A[i])
                swap(A[i], A[A[i] - 1]);
        
        for(int i = 0; i < n; ++ i)
            if(A[i] != i + 1)
                return i + 1;
        
        return n + 1;
    }
};