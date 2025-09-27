class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int l=0;
        int r=0;
        int ans=0;
        int cnt=0;

        while(r<nums.size()){
            

            if(nums[r]==0){
                cnt++;
            }
            while(cnt>1){
                if(nums[l]==0){
                    cnt--;
                }
                l++;
            }
            ans=max(ans,r-l+1);
            r++;

        }
        return ans-1;
    }
};