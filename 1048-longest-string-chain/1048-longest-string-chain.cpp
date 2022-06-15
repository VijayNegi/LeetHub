class Solution {
public:
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(),words.end(),[](string& l,string& r){return l.size()>r.size();});
        int result=1;
        //vector<int> chain(n,0);
        unordered_map<string,int> s;
        for(auto& w:words)
            s[w]=1;
        for(auto& w:words) {
            int k = w.size();
            for(int i=0;i<w.size();++i) {
                string temp = w.substr(0,i) + w.substr(i+1, k-i-1);
                if(s[temp]) {
                    s[temp] = max(s[temp],s[w]+1);
                    result = max(result,s[temp]);
                }
            }
        }
        return result;
    }
};