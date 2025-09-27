class Solution {
public:
    bool canRob(vector<int>& nums,int mid ,int k){
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            if(mid>=nums[i]){
                cnt++;
                i++;
            }

        }
        return (cnt>=k);
    }
    int minCapability(vector<int>& nums, int k) {
        int left=1;
        int right=*max_element(nums.begin(),nums.end());
        int ans=right;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(canRob(nums,mid,k)){
                ans=mid;
                right=mid-1;
            }else{
                left=mid+1;
            }
        }
        return ans;
    }
};