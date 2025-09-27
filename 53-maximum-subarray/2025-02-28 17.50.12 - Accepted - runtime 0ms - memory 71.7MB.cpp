class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0;
        int max_cnt=INT_MIN;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum > max_cnt){
                max_cnt=sum;
            }
            if(sum<0){
                sum=0;
            }
        }
        return max_cnt;
    }
};