class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<bool> hash(256,false);
        int result=0;
        int n = s.size();
        int l=0,r=0;
        while(r<n) {
            if(!hash[s[r]]) {
                hash[s[r++]] = true;
                result = max(result, r-l);
            }
            else {
                hash[s[l++]] = false;
            }
        }
        return result;
        
    }
};