class Solution {
public:
    int slove(vector<int>& nums, int k){
        int l=0;
        int n=nums.size();
        int ans=0;
        map<int,int> mp;
        for(int r=0;r<n;r++){
            mp[nums[r]]++;
            while(mp.size()>k){
                mp[nums[l]]--;
                if(mp[nums[l]]==0){
                    mp.erase(nums[l]);
                }
                l++;
            }
            ans+=(r-l+1);
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return slove(nums,k)-slove(nums,k-1);
    }
};