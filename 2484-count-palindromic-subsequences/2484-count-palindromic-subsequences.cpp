const int mod = 1e9+7;
class Solution {
public:
    // self : TLE
    int countPalindromes1(string s) {
        vector<vector<int>> stk(10);
        int n = s.size();
        for(int i=0;i<s.size();++i){
            stk[s[i]-'0'].push_back(i);
        }
        int result = 0;
        for(int i=0;i<n-4;++i){
            for(int j=i+1;j<n-3;++j){
                int fir = s[i]-'0';
                int sec = s[j]-'0';
                int r  = stk[fir].size()-1;

                for(;r>=0 && stk[fir][r]>j+1;--r){
                    int rr = stk[sec].size()-1;
                    while(rr>=0 && stk[sec][rr] >= stk[fir][r]) --rr;
                    for(;stk[sec][rr]>j+1;--rr){
                        result += (stk[sec][rr]-j)-1;
                        result %=mod;
                    }
                }
            }
        }
        return result;
    }
    int countPalindromes(string s) {
			int n = s.size();
			long ans = 0;
			int ff[10] = {0};
			for(int i = 0;i < n;i++){
				long m = 0;
				for(int j = n-1;j > i;j--){
					if(s[i] == s[j]){
						ans += m * (j-i-1);
//						ans %= mod;
					}
					m += ff[s[j]-'0'];
					if(m >= mod)m -= mod;
				}
				ff[s[i] - '0']++;
			}
			return (int)(ans % mod);
		}
};