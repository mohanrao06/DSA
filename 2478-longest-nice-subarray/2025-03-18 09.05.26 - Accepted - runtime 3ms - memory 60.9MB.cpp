class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int curr=0;
        int res=0;
        int l=0;
        for(int r=0;r<nums.size();r++){
            while(curr & nums[r]){
                curr=curr^nums[l];
                l+=1;
            }
            res=max(res,r-l+1);
            curr=curr|nums[r];

        }
        return res;
        
    }
};