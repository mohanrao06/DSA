class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n=nums.size();
        int l=0;
        int r=0;
        int maxi=0;
        int ans=0;
        unordered_map<int,int> mp;
        while(r<n){
            mp[nums[r]]++;
            maxi=max(maxi,mp[nums[r]]);
            while(maxi>k){
                mp[nums[l]]--;
                maxi=min(maxi,mp[nums[r]]);
                l++;
            }
            ans=max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};