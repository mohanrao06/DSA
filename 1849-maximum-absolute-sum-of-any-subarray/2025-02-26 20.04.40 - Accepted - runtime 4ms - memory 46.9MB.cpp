class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int max_sum=INT_MIN;
        int curr_sum=0;
        for(int i=0;i<nums.size();i++){
            curr_sum+=nums[i];
            max_sum=max(max_sum,curr_sum);
            if(curr_sum<0){
                curr_sum=0;
            }
        }
        vector<int> temp=nums;
        for(int i=0;i<temp.size();i++){
            temp[i]=temp[i]*(-1);
        }
        int min_sum=INT_MIN;
        int curr_sum2=0;
        for(int i=0;i<nums.size();i++){
            curr_sum2+=temp[i];
            min_sum=max(min_sum,curr_sum2);
            if(curr_sum2<0){
                curr_sum2=0;
            }
        }
        return max(max_sum,min_sum);
        

    }
};