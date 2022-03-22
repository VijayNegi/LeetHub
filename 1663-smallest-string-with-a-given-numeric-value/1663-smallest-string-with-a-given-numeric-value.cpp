class Solution {
public:
    string getSmallestString(int n, int k) {
        string s;
        for(int i=n;i>0;--i)
        {
            int t = min(k-i,25);
            s += 'a' + t;
            k -=(t+1);
        }
        reverse(begin(s),end(s));
        return s;
    }
};