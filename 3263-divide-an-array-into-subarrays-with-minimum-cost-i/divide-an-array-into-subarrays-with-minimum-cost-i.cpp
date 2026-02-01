class Solution {
public:
    int minimumCost(vector<int>& nums) {
        sort(nums.begin()+1,nums.end());
        int sum=0;
        for(int i=0;i<3;i++){
            sum+=nums[i];
        }
        return sum;
    }
};