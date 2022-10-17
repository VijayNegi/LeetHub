class Solution {
public:
    bool checkIfPangram(string sentence) {
        bool map[26] = {false};
        for(auto& c: sentence)
            map[c-'a'] = true;
        for(auto& b:map)
            if(b==false) return false;
        return true;
    }
};