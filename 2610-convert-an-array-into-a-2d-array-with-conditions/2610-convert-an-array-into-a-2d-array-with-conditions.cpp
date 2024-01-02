class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>> result;
        unordered_map<int,int> count;
        for(auto& n:nums)
            count[n]++;
        
        while(true){
            vector<int> temp;
            for(auto& n:count){
                if(n.second){
                    temp.push_back(n.first);
                    n.second--;
                }
            }
            if(temp.size()==0)
                break;
            result.push_back(temp);
        }
        return result;
    }
};