class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        sort(words.begin(),words.end(),[](string& l,string& r){return l.size()<r.size();});
        unordered_map<char,vector<string>> dict;
        vector<string> result;
        
        function<bool(string&,int)> dfs = [&](string& str,int idx){
            if(idx == str.size()){
                result.push_back(str);
                return true;
            }
            for(auto& ss: dict[str[idx]]){
                if(ss.size()+idx <= str.size() && ss == str.substr(idx,ss.size()))
                    if(dfs(str,idx+ss.size())) return true;
            }
            return false;
        };
        
        for(auto& w: words){
            dfs(w,0);
            dict[w[0]].push_back(w);
        }
        return result;
    }
};