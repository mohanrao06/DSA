class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        stack<int> st;
        int n = height.size();

        vector<int> NSE(n, n);
        vector<int> PSE(n, -1);

        // Next Greater Element (Right)
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && height[i] <= height[st.top()]) {
                st.pop();
            }
            NSE[i] = !st.empty() ? st.top() : n;
            st.push(i);
        }

        // Clear stack
        st = stack<int>();

        // Previous Greater Element (Left)
        for (int i = 0; i < n; i++) {
            while (!st.empty() && height[i] <= height[st.top()]) {
                st.pop();
            }
            PSE[i] = !st.empty() ? st.top() : -1;
            st.push(i);
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            ans =max(ans,height[i]*(NSE[i]-PSE[i]-1));
        }

        return ans;
    }
};