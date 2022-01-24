class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.size();
        int caps = 0;
        for(int i=0;i<n;++i)
        {
            if(isupper(word[i]))
                ++caps;
            
            if(caps != i+1 && isupper(word[i]))
                return false;
            if(caps > 1 && islower(word[i]))
                return false;
        }
        
        return true;
    }
};