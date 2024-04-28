class StockSpanner {
public:
    stack<int> mono_s;
    vector<int> prices;
    vector<int> span;
    int idx;

    StockSpanner() {
        idx=-1;
    }
    
    int next(int price) {
        idx++;
        prices.push_back(price);
        int ans=1;
        while(!mono_s.empty() && prices[mono_s.top()]<=price){
            ans+=span[mono_s.top()];
            mono_s.pop();
        }
        mono_s.push(idx);
        span.push_back(ans);
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */