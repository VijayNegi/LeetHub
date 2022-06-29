class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end(),[](vector<int>& l,vector<int>& r){
                        if(l[0]==r[0])
                            return l[1]<r[1];
                        return l[0]>r[0];
        });
        vector<vector<int>> result;
        for(auto& p:people) {
            result.insert(next(result.begin(), p[1]),p);
        }
        return result;
    }
};