class Solution {
public:
    // self : 93 ms
    int minimumLengthEncoding1(vector<string>& words) {
        unordered_set<string> s(words.begin(), words.end());
        for (string w : s)
            for (int i = 1; i < w.size(); ++i)
                s.erase(w.substr(i));
        int res = 0;
        for (string w : s) res += w.size() + 1;
        return res;
    }
    // use string view
    int minimumLengthEncoding(vector<string>& words) {
        unordered_set<string_view> S(words.begin(), words.end());
        for (auto& w : words) {
            string_view sv(w);
            for (int i = 1; i < w.size(); i++) S.erase(sv.substr(i));
        }
        return accumulate(S.begin(), S.end(), 0, [](int total, const string_view& w){ return total + w.size() + 1; });
    }
};
