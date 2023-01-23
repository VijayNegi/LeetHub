class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> judge(n+1,0);
        for(auto& v:trust){
            judge[v[0]]--;
            judge[v[1]]++;
        }
        int res = -1;
        for(int i=1;i<=n;++i){
            if(judge[i]==n-1 && res>0) return -1;
            else if(judge[i] == n-1) res = i;
        }
        return res;
    }
};