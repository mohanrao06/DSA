class Solution {
public:

    int bs(int ind,vector<int>& nums,vector<int>& nums1){
        int l=ind;
        int r=nums.size()-1;
        int ans=0;
        while(l<=r){
            int mid=(l+r)/2;
            if(nums[mid]>=nums1[ind]){
                ans=mid;
                l=mid+1;
            }else{
                r=mid-1;
            }

        }
        return ans;
    }
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();

        int m=nums2.size();
        int ans=0;
        for(int i=0;i<n;i++){
            int maxi=bs(i,nums2,nums1);
            ans=max(maxi-i,ans);
        }
        return ans;
    }
};