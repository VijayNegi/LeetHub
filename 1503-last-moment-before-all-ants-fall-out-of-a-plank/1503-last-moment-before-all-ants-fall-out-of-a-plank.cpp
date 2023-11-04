class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int result = 0;
        for(auto& k:right)
            result = max(result,n-k);
        
        for(auto& k:left)
            result = max(result,k);
    
        return result;
        }
};