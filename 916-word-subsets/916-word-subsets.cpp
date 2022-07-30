class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int n = words1.size();
        int m = words2.size();
        vector<vector<int>> hist(n,vector(26,0));
        vector<vector<int>> hist2(m,vector(26,0));
        for(int i=0;i<n;++i) {
            for(auto& c:words1[i]) 
                hist[i][c-'a']++;
        }
        for(int i=0;i<m;++i) {
            for(auto& c:words2[i]) 
                hist2[i][c-'a']++;
        }
        vector<int> acc(26,0);
        
        for(int i=0;i<m;++i) {
            for(int j=0;j<26;++j)
                acc[j] = max(acc[j],hist2[i][j]);
        }
        
        function<bool(vector<int>& ,vector<int>&)> comp = [](vector<int>& v1,vector<int>& v2) {
            for(int i=0;i<26;++i)
                if(v1[i]<v2[i]) return false;
            return true;
        };
        vector<string> result;
        for(int i=0;i<n;++i) 
            if(comp(hist[i],acc)) 
                result.push_back(words1[i]);
        
        return result;
    }
};