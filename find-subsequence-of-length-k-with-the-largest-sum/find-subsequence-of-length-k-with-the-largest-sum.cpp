class Solution {
public:
    //contest solution , 3 ms
    // time : nlog(n)
    // space: O(n)
    vector<int> maxSubsequence1(vector<int>& nums, int k) {
        vector<int> result;
        int n = nums.size();
        vector<int> idxs(n);
        std::iota(idxs.begin(), idxs.end(), 0);
        auto comp = [&](int i,int j)
        {
          if(nums[i]>nums[j])
              return true;
            return false;
        };
        sort(begin(idxs),end(idxs),comp);
        idxs.resize(k);
        sort(begin(idxs),end(idxs));
        for(int i=0;i<k;++i)
        {
            result.push_back(nums[idxs[i]]);
        }
       return result;
    }
    // split point 
    // time : O(n)
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int> tmp = nums;
        nth_element(tmp.begin(), tmp.end()-k, tmp.end());  // sort till k element
        
        int n = nums.size(), threshold = tmp[n-k], larger = 0; 
        for (auto& x : nums) 
            if (x > threshold) ++larger;    
        int equal = k - larger; 
        vector<int> ans; 
        for (auto& x : nums) 
            if (x > threshold) ans.push_back(x); 
            else if (x == threshold && equal) {
                --equal; 
                ans.push_back(x); 
            }
        return ans; 
    }

};