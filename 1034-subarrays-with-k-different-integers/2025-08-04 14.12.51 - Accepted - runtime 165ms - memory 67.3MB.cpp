class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return fun(nums,k)-fun(nums,k-1);
    }
    int fun(vector<int>& nums, int k){
        int l=0;
        int r=0;
        int ans=0;
        map<int,int> mp;
        while(r<nums.size()){
            mp[nums[r]]++;
            while(mp.size()>k){
                mp[nums[l]]--;
                if(mp[nums[l]]==0)mp.erase(nums[l]);
                l++;
            }
            if(mp.size()<=k){
                ans+=(r-l+1);
            }
            r++;
        }
        return ans;
    }
};