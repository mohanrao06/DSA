class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int cnt=0;
        int n=A.size();
        set<int> st;
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(A[i]==B[i])cnt++;
            if(st.count(A[i]))cnt++;
            if(st.count(B[i]))cnt++;
            st.insert(A[i]);
            st.insert(B[i]);
            ans.push_back(cnt);
        }
        return ans;
    }
};