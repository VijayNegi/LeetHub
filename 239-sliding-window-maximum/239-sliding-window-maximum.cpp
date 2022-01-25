class Solution {
public:
    // monotonic queue.
    vector<int> maxSlidingWindow1(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> result;
        deque<int> dq;
        int i=0;
        for(;i<k;++i)
        {
            while(!dq.empty() && nums[dq.back()] <= nums[i])
                dq.pop_back();
            dq.push_back(i);
        }
        result.push_back(nums[dq.front()]);
        for(;i<n;++i)
        {
            while(!dq.empty() && nums[dq.back()] <= nums[i])
                dq.pop_back();
            dq.push_back(i);
            while(!dq.empty() && dq.front() <= i-k)
                dq.pop_front();
            result.push_back(nums[dq.front()]);
        }
        return result;
    }
    // cleaned up
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> result;
        deque<int> dq;
        for(int i=0;i<n;++i)
        { 
            while(!dq.empty() && nums[dq.back()] <= nums[i])
                dq.pop_back();
            dq.push_back(i);
            if(i>=k-1)
            {
                while(!dq.empty() && dq.front() <= i-k)
                dq.pop_front();
                result.push_back(nums[dq.front()]);
            } 
        }
        return result;
    }
};