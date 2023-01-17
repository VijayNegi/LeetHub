class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int result=0,ones=0;
        for(auto& c:s)
            ones += c=='1';
        int n = s.size();
        result = min(n-ones,ones);
        int curr=0;
        for(int i=0;i<n-1;++i){
            curr += s[i]=='1';
            result = min(result,curr +  n-1-i-ones+curr);
        }
        return result;
    }
};