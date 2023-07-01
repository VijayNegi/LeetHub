class Solution {
public:
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> child(k,0);
        int n = cookies.size();
        int result = numeric_limits<int>::max();
        function<void(int)> dfs = [&](int i){
            if(i==n){
                int m = *max_element(begin(child),end(child));
                result = min(m,result);
                return;
            }
            for(int j=0;j<k;++j){
                child[j] += cookies[i];
                dfs(i+1);
                child[j] -= cookies[i];
            }
        };
        dfs(0);
        return result;
    }
};