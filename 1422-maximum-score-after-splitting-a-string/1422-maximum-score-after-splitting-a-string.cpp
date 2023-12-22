class Solution {
public:
    int maxScore(string s) {
        int n = s.size();
        auto sum = [](int ss,char c){
            return ss + c - '0';
        };
        int one = accumulate(begin(s),end(s), 0,sum);
        int result = 0;
        int zero=0;
        for(int i=0;i<n-1;++i){
            if(s[i]=='0')
                zero++;
            else
                one--;
            result = max(result,zero + one);
        }
        return result;
    }
};