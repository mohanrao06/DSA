class Solution {
public:
    void fun(vector<int>& nums,vector<vector<int> >&ans,vector<int>&temp,vector<bool> &visted)
    {
        if(nums.size()==temp.size()){
            ans.push_back(temp);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(visted[i]==0){
                visted[i]=1;
                temp.push_back(nums[i]);
                fun(nums,ans,temp,visted);
                visted[i]=0;
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> >ans;
        vector<int>temp;
        vector<bool> visted(nums.size(),0);
        fun(nums,ans,temp,visted);
        return ans;
        
    }
};