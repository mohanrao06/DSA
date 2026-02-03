class Solution {
public:
    void subseq(vector<int>& nums,int idx,int n,vector<vector<int> >&ans,vector<int> temp){
        if(idx==n){
            ans.push_back(temp);
            return;
        }
        subseq(nums,idx+1,n,ans,temp);
        temp.push_back(nums[idx]);
        subseq(nums,idx+1,n,ans,temp);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        int n=nums.size();
        subseq(nums,0,nums.size(),ans,temp);
        return ans;
    }
};
