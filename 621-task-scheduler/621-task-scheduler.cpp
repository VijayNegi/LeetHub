class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> m;
        int mx = 0;
        for(auto& c: tasks)
        {
            m[c]++;
            mx = max(mx,m[c]);
        }
        int result = (mx-1)*(n+1);
        for(auto it:m)
            if(it.second == mx) ++result;
        return max(result,(int)tasks.size());
    }
};