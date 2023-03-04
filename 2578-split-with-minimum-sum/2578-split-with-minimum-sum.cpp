class Solution {
public:
    int splitNum(int num) {
        vector<int> count(10,0);
        string str= to_string(num);
        int n = str.size();
        for(auto& c:str)
            count[c-'0']++;
        int i=9;
        int result=0;
        int multiple = 1;
        int flag = false;
        while(i>0){
            if(!count[i]){
                --i;
                continue;
            }
            count[i]--;
            result += i*multiple;
            
            if(!flag)
                flag = true;
            else{
                multiple *= 10;
                flag = false;
            }
        }
        return result;
    }
};