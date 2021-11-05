class Solution {
public:
    int arrangeCoins(int n) {
        int count=0;
        int coin = n;
        for(count=1;count<=n && count<=coin ;++count)
            coin-=count;

        return --count;
    }
};