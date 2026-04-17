class Solution {
public:
    int reverse(int n){
        int ans=0;
        while(n>0){
            int rem=n%10;
            ans=ans*10+rem;
            n=n/10;
        }
        return ans;

    }
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n=nums.size();
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            if(mp.find(nums[i])!=mp.end()){
                ans=min(ans,abs(mp[nums[i]]-i));
            }
            int rev=reverse(nums[i]);
            mp[rev]=i;
        }
        if(ans==INT_MAX)return -1;
        return ans;
    }
};