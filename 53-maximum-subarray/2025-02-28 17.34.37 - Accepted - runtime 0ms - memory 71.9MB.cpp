class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cnt=0;
        int max_cnt=INT_MIN;
        for(int i=0;i<nums.size();i++){
            cnt+=nums[i];
            max_cnt=max(cnt,max_cnt);
            if(cnt<0){
                cnt=0;
            }
        }
        return max_cnt;
    }
};