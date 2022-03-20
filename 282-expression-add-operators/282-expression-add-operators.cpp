// 710 ms
// https://leetcode.com/problems/expression-add-operators/discuss/572099/C%2B%2BJavaPython-Backtracking-and-Evaluate-on-the-fly-Clean-and-Concise
class Solution {
public:
    vector<string> ans;
    string s;
    int target;
    vector<string> addOperators1(string s, int target) {
        this->s = s;
        this->target = target;
        backtrack( 0, "", 0, 0);
        return ans;
    }
    void backtrack(int i, const string& path, long resSoFar, long prevNum) {
        if (i == s.length()) {
            if (resSoFar == target) ans.push_back(path);
            return;
        }
        string numStr;
        long num = 0;
        for (int j = i; j < s.length(); j++) {
            if (j > i && s[i] == '0') break; // Skip leading zero number
            numStr += s[j];
            num = num * 10 + s[j] - '0';
            if (i == 0) {
                backtrack(j + 1, path + numStr, num, num); // First num, pick it without adding any operator!
            } else {
                backtrack(j + 1, path + "+" + numStr, resSoFar + num, num);
                backtrack(j + 1, path + "-" + numStr, resSoFar - num, -num);
                backtrack(j + 1, path + "*" + numStr, resSoFar - prevNum + prevNum * num, prevNum * num); // Can imagine with example: 1-2*3
            }
        }
    }
    
    //----------------
    // string operations optimized
    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        string exp(num.length() * 2, '\0');    
        dfs(num, target, 0, exp, 0, 0, 0, ans);
        return ans;
      }
    void dfs(const string& num, const int target,
           int pos, string& exp, int len, long prev, long curr,
           vector<string>& ans) {    
                if (pos == num.length()) {      
                  if (curr == target) ans.push_back(exp.substr(0, len));
                  return;
            }

            long n = 0;
            int s = pos;
            int l = len;
            if (s != 0) ++len;    
            while (pos < num.size()) {      
              n = n * 10 + (num[pos] - '0');
              if (num[s] == '0' && pos - s > 0) break; // 0X... invalid number
              if (n > INT_MAX) break; // too long
              exp[len++] = num[pos++];
              if (s == 0) {
                dfs(num, target, pos, exp, len, n, n, ans);
                continue;
              }
              exp[l] = '+'; dfs(num, target, pos, exp, len, n, curr + n, ans);
              exp[l] = '-'; dfs(num, target, pos, exp, len, -n, curr - n, ans);
              exp[l] = '*'; dfs(num, target, pos, exp, len, prev * n, curr - prev + prev * n, ans);
            }
      }
};
