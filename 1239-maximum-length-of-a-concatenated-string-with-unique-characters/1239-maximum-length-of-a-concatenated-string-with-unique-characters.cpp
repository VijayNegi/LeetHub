class Solution {
public:
    int maxLength(vector<string>& arr) {
        int n = arr.size();
        vector<int> mask;
        for(auto& w:arr) {
            int m=0;
            unordered_set<char> s(w.begin(),w.end());
            if(s.size() != w.size()){
                mask.push_back(m);
                continue;
            }
            for(auto& c:w){
                m |= 1<<(c-'a'); 
            }
            //cout<<m<<" ";
            mask.push_back(m);
        }
        
        function<int(int,int,int)> dfs = [&](int k, int m, int l){
            int len = l;
            //cout<<"dfs ="<<k<<" "<<m<<" "<<l<<endl;
            while(k<n){
                if(mask[k] && !(m & mask[k])){
                    len = max(len,dfs(k+1,m | mask[k],l+arr[k].size()));
                }
                ++k;
            }
            //cout<<len<<endl;
            return len;
        };
        
        return dfs(0,0,0);
    }
};