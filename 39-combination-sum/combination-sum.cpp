class Solution {
public:
    void fun(vector<int>& nums, int target,int ind,vector<int> &temp,vector<vector<int>> & ans){
        if (target < 0) return;
        if(ind==nums.size()){
            if(target==0){
                ans.push_back(temp);
            }
            return ;
        }
        fun(nums,target,ind+1,temp,ans);
        temp.push_back(nums[ind]);
        fun(nums,target-nums[ind],ind,temp,ans);
        temp.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        fun(candidates,target,0,temp,ans);
        return ans;
    }
};