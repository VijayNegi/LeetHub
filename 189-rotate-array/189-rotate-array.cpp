class Solution {
public:
    int gcd (int a, int b) 
    {
        while (b) {
            a %= b;
            swap(a, b);
        }
        return a;
    }
    void rotate(vector<int>& nums, int k) {
        
        int n = nums.size();
        k%=n;
        while(k>0)
        {
            int p = k;
            
            while(gcd(n,p)!=1)
                --p;
            k -=p;
            
            int idx = (p)%n;
            int value = nums[0];
            int counter = n;
            while(counter-->=0)
            {
                swap(nums[idx],value);
                idx = (idx+p)%n;
            }
        }
        
        
        return;
    }
};