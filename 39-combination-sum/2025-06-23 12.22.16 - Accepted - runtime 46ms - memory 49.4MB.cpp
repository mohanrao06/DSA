class Solution {
public:
    void fun(int i,vector<vector<int>> &ans,int target,int n,vector<int> arr,vector<int> &temp){
        if(i==n){
            if(target==0){
                ans.push_back(temp);
                
                
            }
            return;
        }
        if(arr[i]<=target){
            temp.push_back(arr[i]);
            fun(i,ans,target-arr[i],n,arr,temp);
            temp.pop_back();
            
        }
        fun(i+1,ans,target,n,arr,temp);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        int n=candidates.size();
        vector<int> temp;
        fun(0,ans,target,n,candidates,temp);
        return ans;
    }
};