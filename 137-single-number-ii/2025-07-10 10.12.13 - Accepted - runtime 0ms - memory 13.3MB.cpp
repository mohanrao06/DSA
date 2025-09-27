class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones=0,tows=0;
        for(int i=0;i<nums.size();i++){
            ones=(ones^nums[i]&(~tows));
            tows=(tows^nums[i]&(~ones));
        }
        return ones;
    }
};