class Solution {
public:
    int find(vector<int> &heights){
        stack<int> st;
        int ans=0;
        for(int i=0;i<heights.size();i++){
            while(!st.empty() && heights[st.top()]>heights[i]){
                int idx=st.top();
                st.pop();
                int nse=i;
                int pse=st.empty()?-1:st.top();
                ans=max(ans,heights[idx]*(nse-pse-1));
            }
            st.push(i);
        }
        while(!st.empty()){
            int nse=heights.size();
            int idx=st.top();
            st.pop();
            int pse=st.empty()?-1:st.top();
            ans=max(ans,heights[idx]*(nse-pse-1));
        }
        return ans;

    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int ans=0;
        vector<int> hights(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='0'){
                    hights[j]=0;
                }else{
                    hights[j]++;
                }
            }
            ans=max(ans,find(hights));
        }
        return ans;
    }
};