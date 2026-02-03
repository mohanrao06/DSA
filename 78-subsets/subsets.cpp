class Solution {
public:
    void fun(vector<int> &nums,int ind,vector<int> &temp,vector<vector<int>> &ans){
        if(ind==nums.size()){
            ans.push_back(temp);
            return;
        }
        fun(nums,ind+1,temp,ans);
        temp.push_back(nums[ind]);
        fun(nums,ind+1,temp,ans);
        temp.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> ans;
        fun(nums,0,temp,ans);
        return ans;


    }
};