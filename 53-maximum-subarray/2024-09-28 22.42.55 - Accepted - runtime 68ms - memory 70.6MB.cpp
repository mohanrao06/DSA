class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int count=0;
        int maxi= INT_MIN;
        for(int i=0;i<nums.size();i++){
            count+=nums[i];
            maxi=max(count,maxi);
            if(count<0){
                count=0;
            }
        }
        return maxi;
    }
};