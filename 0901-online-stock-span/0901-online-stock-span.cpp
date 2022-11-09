class StockSpanner {
    int day{0};
    vector<vector<int>> mstk;
public:
    StockSpanner() {
    }
    
    int next(int price) {
        ++day;
        while(mstk.size() && mstk.back()[1]<=price)
            mstk.pop_back();
        int result = mstk.size()? day - mstk.back()[0]: day;
        mstk.push_back({day,price});
        return result;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */