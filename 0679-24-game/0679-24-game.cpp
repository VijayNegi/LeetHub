class Solution {
public:
    double elipson = pow(10.0, -5);
    vector<char> operations = {'+','-','*','/'};
        // https://leetcode.com/problems/24-game/discuss/107685/679.-24-Game-C%2B%2B-Recursive
    bool judgePoint24(vector<int>& nums) {
        vector<double> vec;
        for(auto n : nums){
            vec.push_back(n*1.0);
        }
        return find24(vec);
    }

    bool find24(vector<double> vec){
        if(vec.size() == 1){
            return abs(vec[0] - 24.0) <= elipson;
        }
        for(int i = 0; i < vec.size(); ++i){//each time we pick up two number for computation
            for(int j = 0; j < vec.size(); ++j){
                if(i == j) continue;
                vector<double> res;
                for(int k = 0; k < vec.size(); ++k){
                    if(k != i && k != j) res.push_back(vec[k]);
                }
                for(auto op : operations){
                    if((op == '+' || op == '*') && i > j) continue;//no need to re-calculate
                    if(op =='/'  && vec[j] == 0.0) continue;
                    switch(op){
                        case '+': res.push_back(vec[i] + vec[j]); break;
                        case '-': res.push_back(vec[i] - vec[j]); break;
                        case '*': res.push_back(vec[i] * vec[j]); break;
                        case '/': res.push_back(vec[i] / vec[j]); break;
                    }
                    if(find24(res)) return true;
                    res.pop_back();//!!!important
                }
            }
        }
        return false;
    }
};