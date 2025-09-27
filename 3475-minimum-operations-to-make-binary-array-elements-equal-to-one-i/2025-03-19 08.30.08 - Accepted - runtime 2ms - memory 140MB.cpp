class Solution {
public:
    void filp(vector<int>& nums,int i){
        nums[i]=1-nums[i];
    }
    int minOperations(vector<int>& nums) {
        int res=0;
        for(int i=0;i<nums.size()-2;i++){
            if(nums[i]==0){
                filp(nums,i);
                filp(nums,i+1);
                filp(nums,i+2);


                res++;
            }
             
        }
        if(nums[nums.size()-1]==0 || nums[nums.size()-2]==0){
            return -1;
        }







        return res;
    }
};