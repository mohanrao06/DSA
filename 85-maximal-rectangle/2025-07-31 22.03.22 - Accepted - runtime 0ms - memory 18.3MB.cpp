class Solution {
public:
int largestRectangleArea(vector<int>& heights) {
        int ans=0;
        stack<int> st;
        for(int i=0;i<heights.size();i++){
            while(!st.empty() && heights[st.top()]>heights[i]){
                int ele=st.top();
                st.pop();
                int nse=i;
                int pse=st.empty()?-1:st.top();
                ans=max(ans,heights[ele]*(nse-pse-1));
            }
            st.push(i);
        }
        while(!st.empty()){
            int ele=st.top();
                st.pop();
                int nse=heights.size();
                int pse=st.empty()?-1:st.top();
                ans=max(ans,heights[ele]*(nse-pse-1));
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<int> right(matrix[0].size(),0);
        int ans=0;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]=='0'){
                    right[j]=0;
                }else{
                    right[j]++;
                }
            }
            ans=max(ans,largestRectangleArea(right));
        }
        return ans;
    }
};