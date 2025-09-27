class StockSpanner {
public:
    stack<pair<int, int>> st; // {price, span}

    StockSpanner() {}

    int next(int price) {
        int span = 1;

        // Pop all prices less than or equal to current price
        while (!st.empty() && st.top().first <= price) {
            span += st.top().second;
            st.pop();
        }

        st.push({price, span});
        return span;
    }
};
