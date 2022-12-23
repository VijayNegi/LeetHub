class Solution {
public:
    //https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/discuss/75927/Share-my-thinking-process
    int maxProfit(vector<int> &prices) {
        int buy(INT_MIN), sell(0), prev_sell(0), prev_buy;
        for (int price : prices) {
            prev_buy = buy;
            buy = max(prev_sell - price, buy);
            prev_sell = sell;
            sell = max(prev_buy + price, sell);
        }
        return sell;
    }
};