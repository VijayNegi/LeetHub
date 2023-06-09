class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        auto it = upper_bound(begin(letters),end(letters),target);
        if(it == letters.end())
            return letters[0];
        return *it;
    }
};