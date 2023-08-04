class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<vector<int>> char2Dict(26);
        int n = s.size();
        //sort(begin(wordDict),end(wordDict),[](string& l,string& r){ return l.size()>r.size();});
        for(int i=0;i<wordDict.size();++i){
            char2Dict[wordDict[i][0]-'a'].push_back(i);
        }
        vector<bool> dp(n,false);
        function<bool(int)> dfs = [&](int pos){
            if(pos==n) return true;
            if(dp[pos]==true) return false;
            dp[pos]=true;
            for(auto& i: char2Dict[s[pos]-'a']){
                
                string& w = wordDict[i];
                if(w.size()+pos > n)
                    continue;
                int k=0,p1 = pos;
                while(k<w.size() && p1<n){
                    if(w[k]==s[p1]){
                        ++k,++p1;
                    }
                    else 
                        break;
                }
                if(k==w.size() && dfs(p1))
                    return true;
                    
            }
            return false;
        };
        return dfs(0);
    }
};

