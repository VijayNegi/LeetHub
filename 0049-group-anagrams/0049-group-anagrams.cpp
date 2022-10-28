class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        vector<pair<string,int>> sorted;
        for(int i=0;i<strs.size();++i){
            string s = strs[i];
            sort(s.begin(),s.end());
            sorted.push_back({s,i});
        }
        sort(sorted.begin(),sorted.end());
        string pre="-";
        for(auto& s:sorted){
            if(s.first != pre)
                result.push_back({strs[s.second]});
            else
                result.back().push_back(strs[s.second]);
            pre = s.first;
        }
        return result;    
    }
};