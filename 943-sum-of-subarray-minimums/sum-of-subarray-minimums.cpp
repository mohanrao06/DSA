class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        long long ans=0;
        int n=arr.size();
        int MOD = 1000000007;
        vector<int> Nse =NSE(arr,n);
        vector<int> pse =PSE(arr,n);
        for(int i=0;i<n;i++){
            int left=i-pse[i];
            int right=Nse[i]-i;
            ans=(ans+ (long)arr[i]*left*right)%MOD;

        }
        return (int)ans;

        
    }
    vector<int> NSE(vector<int>& arr,int n){
        vector<int> ans(n,n);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[i]<=arr[st.top()]){
                st.pop();
            }

            ans[i]=!st.empty()?st.top():n;
            st.push(i);
        }
        return ans;

    }
    vector<int> PSE(vector<int>& arr,int n){
        vector<int> ans(n,-1);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[i]<arr[st.top()]){
                st.pop();
            }
            ans[i]=!st.empty()?st.top():-1;
            st.push(i);
        }
        return ans;

    }
};