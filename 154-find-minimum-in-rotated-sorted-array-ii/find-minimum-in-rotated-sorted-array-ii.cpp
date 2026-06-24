class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0;
        int r=nums.size()-1;
        if(nums.size()==1)return nums[0];
        int ans=0;
        while(l<r){
            int mid=(l+r)/2;
            if(nums[mid]>nums[r]){
                ans=nums[r];
                l=mid+1;
            }else if(nums[mid]<nums[r]){
                ans=nums[mid];
                r=mid;
            }else{
                ans=nums[mid];
                r--;
            }
        }
        return ans;    
    }
};