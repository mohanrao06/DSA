class Solution {
public:
    vector<int> NSE(vector<int> arr){
        vector<int> ans(arr.size());
        stack<int> st;
        for(int i=arr.size()-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }
            ans[i]=st.empty()?arr.size():st.top();
            st.push(i);
        }
        return ans;

    }
    vector<int> PSE(vector<int> arr){
        vector<int> ans(arr.size());
        stack<int> st;
        for(int i=0;i<arr.size();i++){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            ans[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        return ans;

    }
    long long sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> nse = NSE(arr);
        vector<int> pse = PSE(arr);
        int MOD = 1000000007;
        long long ans = 0;
        

        for(int i = 0; i < n; i++){
            int left = i - pse[i];
            int right = nse[i] - i;

            ans = (ans + (long) arr[i] * left * right);
        }

        return ans;
    }
     vector<int> NGE(vector<int> arr){
        vector<int> ans(arr.size());
        stack<int> st;
        for(int i=arr.size()-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]<arr[i]){
                st.pop();
            }
            ans[i]=st.empty()?arr.size():st.top();
            st.push(i);
        }
        return ans;

    }
    vector<int> PGE(vector<int> arr){
        vector<int> ans(arr.size());
        stack<int> st;
        for(int i=0;i<arr.size();i++){
            while(!st.empty() && arr[st.top()]<=arr[i]){
                st.pop();
            }
            ans[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        return ans;

    }
    long long sumSubarrayMax(vector<int>& arr) {
        int n = arr.size();
        vector<int> nse = NGE(arr);
        vector<int> pse = PGE(arr);
        int MOD = 1000000007;
        long long ans = 0;
        

        for(int i = 0; i < n; i++){
            int left = i - pse[i];
            int right = nse[i] - i;

            ans = (ans + (long) arr[i] * left * right);
        }

        return ans;
    }
    long long subArrayRanges(vector<int>& nums) {
        return (long long)sumSubarrayMax(nums)-sumSubarrayMins(nums);
    }
};