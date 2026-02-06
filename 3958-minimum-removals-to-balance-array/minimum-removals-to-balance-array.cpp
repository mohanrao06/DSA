class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int cnt=0;
        if(nums.size()==1)return 0;
        int mini=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]<nums[mini]){
                mini=i;
            }
            if((long long)nums[mini]*k<nums[i]){
                mini++;
                cnt++;
            }
        }
        return cnt;
    }
};