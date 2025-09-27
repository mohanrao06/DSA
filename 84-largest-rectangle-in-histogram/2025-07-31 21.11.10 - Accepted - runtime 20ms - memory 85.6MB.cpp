class Solution {
public:
    
    int largestRectangleArea(vector<int>& heights) {
        vector<int> right(heights.size());
        vector<int> left(heights.size());
        stack<int> st;
        for(int i=heights.size()-1;i>=0;i--){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.empty())right[i]=heights.size();
            else{
                right[i]=st.top();
            }
            st.push(i);
        }
        stack<int> st1;
        for(int i=0;i<heights.size();i++){
            while(!st1.empty() && heights[st1.top()]>=heights[i]){
                st1.pop();
            }
            if(st1.empty())left[i]=-1;
            else{
                left[i]=st1.top();
            }
            st1.push(i);
        }
        int ans=0;
        for(int i=0;i<heights.size();i++){
            ans=max(ans,heights[i]*(right[i]-left[i]-1));
        }
        return ans;
    }
};