class Solution {
public:
    // nth_elements : 4 ms
    int findKthLargest1(vector<int>& nums, int k) {
        nth_element(nums.begin(), nums.begin() + k - 1, nums.end(), greater<int>());
        return nums[k - 1];
    }
    // partial_sort : 15ms
    int findKthLargest2(vector<int>& nums, int k) {
        partial_sort(nums.begin(), nums.begin() + k, nums.end(), greater<int>());
        return nums[k - 1];
    }
    // min heap :  4 ms
    int findKthLargest3(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int num : nums) {
            pq.push(num);
            if (pq.size() > k) {
                pq.pop();
            }
        }
        return pq.top();
    }
    // min heap multiset :  4 ms
    int findKthLargest(vector<int>& nums, int k) {
        multiset<int> mset;
        for (int num : nums) {
            mset.insert(num);
            if (mset.size() > k) {
                mset.erase(mset.begin());
            }
        }
        return *mset.begin();
    }

};