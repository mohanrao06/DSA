class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int sum=0;
        int maxi=*max_element(nums.begin(),nums.end());
        int mini=*min_element(nums.begin(),nums.end());
        unordered_set<int> st(nums.begin(),nums.end());
        vector<int> ans;
        for(int i=mini;i<=maxi;i++){
            if(st.find(i)==st.end()){
                ans.push_back(i);
            }
        }
        return ans;
    }
};