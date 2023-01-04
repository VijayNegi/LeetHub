class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int> freq;
        for(auto& t:tasks)
            freq[t]++;
        int result=0;
        for(auto& t:freq){
            if(t.second ==1)
                return -1;
            result += t.second/3;
            if(t.second%3)
                ++result;
        }
        return result;
    }
};