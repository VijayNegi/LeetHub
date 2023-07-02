class Solution {
public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        int nr = requests.size();
        int ans = 0;
        for (int mask = 0; mask < (1 << nr); mask++){
            vector<int> out(n, 0), in(n, 0);
            for (int i = 0; i < nr; i++){
                if ((mask&(1 << i))){
                    out[requests[i][0]] += 1;
                    in[requests[i][1]] += 1;
                }
            }
            if (out == in){
                int temp = 0; 
                for (auto& v: out) temp += v;
                ans = max(ans, temp);
            }
        }
        return ans;
    }
};