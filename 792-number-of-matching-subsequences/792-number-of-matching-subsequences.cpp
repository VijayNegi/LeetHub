class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int n = s.size();
        function<bool(const string&)> match = [&](const string& str) {
            int i=0,j=0;
            int sn = str.size();
            if(sn>n)
                return false;
            while(i<n && j<sn) {
                if(s[i++]==str[j])
                    ++j;
            }
            return j==sn;
        };
        int result=0;
        map<string,int> unique;
        for(auto& w:words)
            unique[w]++;
        for(auto& w:unique){
            if(match(w.first))
                result+=w.second;
        }
        return result;
    }
};