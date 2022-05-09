class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty())
            return {};
        vector<string> mp{"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> result{""};
        for(auto c:digits)
        {
            int d = c-'0';
            vector<string> temp;
            for(auto& ch:mp[d])
                for(auto& s:result)
                    temp.push_back(s+ch);
            swap(result,temp);
        }
        return result;
    }
};