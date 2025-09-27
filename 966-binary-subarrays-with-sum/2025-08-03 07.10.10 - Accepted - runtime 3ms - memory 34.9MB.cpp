class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return fun(nums,goal)-fun(nums,goal-1);
    }
    int fun(vector<int> nums, int goal){
        int ans=0;
        int sum=0;
        int l=0;
        if(goal<0)return 0;
        
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            while(sum>goal){
                sum-=nums[l];
                l++;
            }
            ans=ans+(i-l+1);
            

        }
        return ans;
    }
};