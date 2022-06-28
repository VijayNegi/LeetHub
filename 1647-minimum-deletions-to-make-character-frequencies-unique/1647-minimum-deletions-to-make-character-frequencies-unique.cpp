class Solution {
public:
    int minDeletions(string s) {
        vector<int> freq(26,0);
        for(auto& c:s) {
            freq[c-'a']++;
        }
        sort(freq.begin(),freq.end());
        unordered_set<int> ss;
        int result = 0;
        for(int i=0;i<26;++i) {
            if(freq[i]==0)
                continue;
            if(ss.count(freq[i])==0) {
                ss.insert(freq[i]);
            }
            else {
                int org = freq[i];
                while(org>0 && ss.count(org)==1)
                    org--;
                ss.insert(org);
                result += freq[i]-org;
            }
        }
        return result;
    }
};