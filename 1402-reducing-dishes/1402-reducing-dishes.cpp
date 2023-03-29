class Solution {
public:
    int maxSatisfaction(vector<int>& sat) {
        sort(begin(sat),end(sat));
        int result = 0,n=sat.size();
        for(int i=0;i<n;++i){
            int curr=0;
            for(int j=i;j<n;++j){
                curr += sat[j]*(j-i+1);
            }
            result = max(result,curr);
        }
        return result;
    }
};