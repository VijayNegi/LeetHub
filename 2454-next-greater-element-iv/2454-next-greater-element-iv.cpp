class Solution {
public:
    vector<int> secondGreaterElement(vector<int>& nums) {
        int n =nums.size();
        vector<int> nextGreater(n,n);
        vector<int> stk;
        for(int i=n-1;i>=0;--i){
            while(stk.size() && nums[stk.back()]<= nums[i])
                stk.pop_back();
            if(stk.size())
                nextGreater[i] = stk.back();
            stk.push_back(i);
        }
        vector<int> result;
        for(int i=0;i<n;++i){
            if(nextGreater[i]==n){
                result.push_back(-1);
            }
            else{
                int pos = nextGreater[i]+1;
                while(pos<n && nums[pos]<=nums[i] )
                    pos = nextGreater[pos];
                if(pos<n)
                    result.push_back(nums[pos]);
                else
                    result.push_back(-1); 
            }
        }
        
        return result;
    }
};