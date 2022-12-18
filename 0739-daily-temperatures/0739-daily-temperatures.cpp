class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();
        vector<int> res(n,0),stk;
        for(int i=n-1;i>=0;--i){
            while(stk.size() && temp[stk.back()] <= temp[i])
                stk.pop_back();
            if(stk.empty()){
                res[i]=0;
                stk.push_back(i);
            }
            else {
                res[i] = stk.back()-i;
                stk.push_back(i);
            }
        }
        return res;
    }
};