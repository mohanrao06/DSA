class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int target= *max_element(nums.begin(),nums.end());
        int res=0;
        int size=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target){
                size++;

            }
            else{
                size=0;
            }
            res=max(res,size);

        }
        return res;

    }
};