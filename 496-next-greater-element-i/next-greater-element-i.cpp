class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums2.size();
        vector<int> ans(n,-1);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top()<=nums2[i]){
                st.pop();
            }
            ans[i]=!st.empty()?st.top():-1;
            st.push(nums2[i]);
        }
        map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[nums2[i]]=ans[i];
        }
        vector<int> res;
        for(int i=0;i<nums1.size();i++){
            res.push_back(mp[nums1[i]]);
        }
        return res;
    }
};