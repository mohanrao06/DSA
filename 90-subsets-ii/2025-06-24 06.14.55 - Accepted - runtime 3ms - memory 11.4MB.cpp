class Solution {
public:
    void fun(int ind,int n,vector<vector<int>> &ans,vector<int> temp,vector<int> arr){
        
            ans.push_back(temp);
        
        
        for(int i=ind;i<n;i++){
            if(i>ind && arr[i]==arr[i-1])continue;
            temp.push_back(arr[i]);
            fun(i+1,n,ans,temp,arr);
            temp.pop_back();
            
        }
        
        

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> temp;
        int n=nums.size();
        fun(0,n,ans,temp,nums);
        return ans;
    }
};