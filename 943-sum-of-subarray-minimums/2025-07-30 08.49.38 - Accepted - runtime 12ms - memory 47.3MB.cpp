class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> nse = findNSE(arr);
        vector<int> pse = FindPSEE(arr);
        int MOD = 1000000007;
        long ans = 0;
        

        for(int i = 0; i < n; i++){
            int left = i - pse[i];
            int right = nse[i] - i;

            ans = (ans + (long) arr[i] * left * right) % MOD;
        }

        return (int) ans;
    }
    vector<int> findNSE(vector<int>& arr){
        stack<int> st;
        vector<int> res(arr.size());

        for(int i = arr.size() - 1; i >= 0; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();

            res[i] = st.empty() ? arr.size() : st.top();
            st.push(i);
        }
        return res;
    }

    vector<int> FindPSEE(vector<int>& arr){
        stack<int> st;
        vector<int> res(arr.size());

        for(int i = 0; i < arr.size() ; i++){
            while(!st.empty() && arr[st.top()] > arr[i]) st.pop();

            res[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return res;
    }

};