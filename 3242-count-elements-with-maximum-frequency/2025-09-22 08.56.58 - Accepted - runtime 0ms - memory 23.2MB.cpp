class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        map<int,int> mp;
        int maxi=0;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
            maxi=max(mp[nums[i]],maxi);
        }
        int ans=0;
        for(auto it:mp){
            if(it.second==maxi){
                ans+=it.second;
            }
        }
        return ans;
        

    }
};