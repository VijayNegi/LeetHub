class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.size();
        int count=0;
        for(auto& c:word)
            if(toupper(c)==c)
                ++count;
        if(count==0 || count==n || (count==1 && toupper(word[0]) == word[0]))
            return true;
        return false;
    }
};