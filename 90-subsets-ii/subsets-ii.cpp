class Solution {
public:
    void fun(vector<int> &arr,int ind,vector<vector<int>> &ans,vector<int>& temp){
        ans.push_back(temp);
        for(int i=ind;i<arr.size();i++){
            if(i>ind && arr[i]==arr[i-1])continue;
            temp.push_back(arr[i]);
            fun(arr,i+1,ans,temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
         vector<vector<int>> ans;
         vector<int> temp;
         fun(nums,0,ans,temp);
         return ans;
    }
};