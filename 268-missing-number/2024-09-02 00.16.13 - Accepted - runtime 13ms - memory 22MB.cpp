class Solution {
public:
    int missingNumber(vector<int>& nums) {
        vector<int> ans(nums.size()+1,0);
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            ans[nums[i]]++;
        }
        
        for(int j=0;ans.size();j++){
            if(ans[j]==0){
                return j;
            }
        }
        return ans[1];
    }
};