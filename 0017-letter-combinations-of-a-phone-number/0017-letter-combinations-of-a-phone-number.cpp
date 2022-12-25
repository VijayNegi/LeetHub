class Solution {
public:
    vector<string> letterCombinations1(string digits) {
        vector<string> m{"", "","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> result;
        string s;
        int n = digits.size();
        if(!n)  return result;
        function<void(int)> dfs = [&](int pos)
        {
            if(pos==n)
            {
                result.push_back(s);
                return;
            }
            int i = digits[pos]-'0';
            for(auto ch: m[i])
            {
                s.push_back(ch);
                dfs(pos+1);
                s.pop_back();
            }
        };
        dfs(0);
        return result;
    }
    
    vector<string> letterCombinations(string digits) {
        if(digits.empty())  return {};
        vector<string> mp{"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> result{""};
        for(auto d:digits)
        {
            vector<string> temp;
            for(auto& ch:mp[d-'0'])
                for(auto& s:result)
                    temp.push_back(s+ch);
            result = move(temp);
        }
        return result;
    }
};