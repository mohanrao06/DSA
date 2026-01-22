class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans=INT_MIN;
        if(nums.size()==1){
            return nums[0];
        }
        int pre=1;
        int suf=1;

        for(int i=0;i<nums.size();i++){
            pre*=nums[i];
            suf*=nums[nums.size()-1-i];
            
            ans=max(ans,max(pre,suf));
            if(pre==0)pre=1;
            if(suf==0)suf=1;
        }
        return ans;
    }
};