class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> PSE(n,-1);
        vector<int> NSE(n,n);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            PSE[i]=!st.empty()?st.top():-1;
            st.push(i);
        }
        st = stack<int>();
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()]>= heights[i]){
                st.pop();
            }
            NSE[i]=!st.empty()?st.top():n;
            st.push(i);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,heights[i]*(NSE[i]-PSE[i]-1));
        }
        return ans;
        
    }
};