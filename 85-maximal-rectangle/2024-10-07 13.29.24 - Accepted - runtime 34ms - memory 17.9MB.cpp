class Solution {

    int findRec(vector<int>& heights){
        int ans=0;
        int n=heights.size();
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>heights[i]){
                int index=st.top();
                st.pop();
                if(!st.empty()){
                    ans=max(ans,heights[index]*(i - st.top()-1));

                }else{
                    ans=max(ans,heights[index]*i);
                }
            }
            st.push(i);
        }
        while(!st.empty()){
            int index=st.top();
            st.pop();
             if(!st.empty()){
                    ans=max(ans,heights[index]*(n - st.top()-1));

                }else{
                    ans=max(ans,heights[index]*n);
                }

        }
        return ans;
    }

public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int an=0;
        int row=matrix.size();
        int col=matrix[0].size();
        vector<int> heights(col);
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(matrix[i][j]=='0')
                    heights[j]=0;
                else
                    heights[j]+=1;
            }
            an=max(an,findRec(heights));
        }
        return an;
    
    }
};