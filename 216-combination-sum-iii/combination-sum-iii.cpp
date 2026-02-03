class Solution {
public:
    void fun(int k,int target,int ind,int sum,vector<vector<int>> &ans,vector<int> &temp){
        if(temp.size()==k && target==sum){
            ans.push_back(temp);
            return ;
        }
        if(temp.size()>k|| sum>target)return;
        for(int i=ind;i<=9;i++){
            temp.push_back(i);
            fun(k,target,i+1,sum+i,ans,temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;
        fun(k,n,1,0,ans,temp);
        return ans;
    }
};