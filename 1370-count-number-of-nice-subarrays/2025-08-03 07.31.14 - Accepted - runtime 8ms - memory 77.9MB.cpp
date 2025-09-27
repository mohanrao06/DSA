class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
       return fun(nums,k)-fun(nums,k-1);

    }
    int fun(vector<int> nums, int goal){
        int ans=0;
        int sum=0;
        int l=0;
        if(goal<0)return 0;
        
        for(int i=0;i<nums.size();i++){
            sum+=nums[i]%2?1:0;
            while(sum>goal){
                sum-=nums[l]%2?1:0;
                l++;
            }
            ans=ans+(i-l+1);
            

        }
        return ans;
    }
};