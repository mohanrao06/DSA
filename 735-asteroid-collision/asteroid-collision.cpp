class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        stack<int> st;
        int n=arr.size();
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(arr[i]>0){
                st.push(arr[i]);
            }else{
                while(!st.empty() && st.top() >0 && abs(arr[i])>st.top()){
                    st.pop();
                }
                if(!st.empty() && st.top() >0 && abs(arr[i])==st.top())st.pop();
                else if(st.empty() || st.top()<0)st.push(arr[i]);

            }
        }

        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};