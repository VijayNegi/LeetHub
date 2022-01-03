class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> trustCount(n+1,0);
        //vector<int> trustCount(n,0);
        
        for(auto& t: trust)
        {
            trustCount[t[0]] = -1; // cant be a judge
            if(trustCount[t[1]]>=0)
                trustCount[t[1]]++;
        }
        int judge = -1;
        for(int i=1;i<=n;++i)
        {
            if(trustCount[i]==n-1)
            {
                judge = i;
                break;
            }
                
        }
        return judge;
    }
};