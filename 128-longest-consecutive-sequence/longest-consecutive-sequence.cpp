class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        if (nums.empty()) return 0;
        int n=nums.size();
        int cnt=0;
        int ans=1;
        int last=INT_MIN;
        for(int i=0;i<n;i++){
            if(nums[i]-1==last){
                cnt++;
                last=nums[i];
            }
            else if(nums[i]!=last){
                last=nums[i];
                cnt=1;
            }
            ans=max(cnt,ans);
        }
        return ans;
        
    }
};