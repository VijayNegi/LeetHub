class Solution {
public:
    string getSmallestString(int n, int k) {
        string s;
        while(n>0)
        {
            if(n==k)
            {
                 s += 'a';
                --n;--k;
            }
            else
            {
                int t = min(k-n,25);
                s += 'a' + t;
                --n; k -=(t+1);
            }
        }
        reverse(begin(s),end(s));
        return s;
    }
};