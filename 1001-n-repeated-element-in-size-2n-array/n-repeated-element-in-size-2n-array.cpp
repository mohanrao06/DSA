class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        map<int,int> mp;
        int size=nums.size();
        int n=size/2;
        for(int i=0;i<size;i++){
            mp[nums[i]]++;

        }
        int ans=0;
        for(auto it: mp){
            if(it.second==n){
                ans=it.first;
            }
        }
        return ans;
    }
};