class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        int n = obstacles.size();
        
        // O(nlogn) binary search store LIS
        vector<int> lis;
        vector<int> res;
        for (auto &num : obstacles) {
            auto it = upper_bound(lis.begin(), lis.end(), num);
            
            if (it == lis.end()) {
                lis.push_back(num);
                res.push_back(lis.size());
            }
            else {
                int d = distance(lis.begin(),it) +1;
                if(*it==num )
                    ++d;
                *it = num;
                res.push_back(d);
            }
        }
        
        return res;
    
    }
};