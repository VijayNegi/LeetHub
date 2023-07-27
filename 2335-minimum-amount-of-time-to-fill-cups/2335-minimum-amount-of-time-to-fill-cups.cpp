class Solution {
public:
    //https://leetcode.com/problems/minimum-amount-of-time-to-fill-cups/discuss/2261394/JavaC%2B%2BPython-max(max(A)-(sum(A)-%2B-1)-2) 
     int fillCups(vector<int>& A) {
        int mx = 0, sum = 0;
        for(int& a: A) {
            mx = max(a, mx);
            sum += a;
        }
        return max(mx, (sum + 1) / 2);
    }
};