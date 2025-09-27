class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long xorr=0;
        for(int i=0;i<nums.size();i++)xorr=xorr^nums[i];
        int b1=0,b2=0;
        int rightmost=(xorr&(xorr-1))^xorr;
        for(int i=0;i<nums.size();i++){
            if(rightmost&nums[i]){
                b1=b1^nums[i];
            }
            else{
                b2=b2^nums[i];
            }

        }
        return {b1,b2};
    }
};