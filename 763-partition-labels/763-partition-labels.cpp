class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        vector<int> start(26,n+1),end(26,-1);
        
        for(int i=0;i<n;++i)
        {
            start[s[i]-'a'] = min(i,start[s[i]-'a'] );
            end[s[i]-'a'] = max(i,end[s[i]-'a'] );
        }
        vector<int> result;
        int l=0,r=0;
        for(int i=0;i<n;++i)
        {
            if(r<i)
            {
                result.push_back(r-l+1);
                l = start[s[i]-'a'];
                r = end[s[i]-'a'];
            }
            else
            {
                r = max(r,end[s[i]-'a']);
            }
        }
        result.push_back(r-l+1);
        return result;
    }
};