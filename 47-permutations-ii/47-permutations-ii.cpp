class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> st;
        vector<vector<int>> result;
        std::sort(nums.begin(), nums.end());
        do {
            result.push_back(nums);
        } while(std::next_permutation(nums.begin(), nums.end()));
        return result;
    }
};