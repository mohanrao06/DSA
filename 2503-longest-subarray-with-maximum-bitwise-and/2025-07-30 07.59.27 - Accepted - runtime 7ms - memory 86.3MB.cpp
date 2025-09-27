class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        
        int res=0;
        int size=0;
        int curr_max=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>curr_max){
                curr_max=nums[i];
                size=1;
                res=0;
            }else if(nums[i]==curr_max){
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