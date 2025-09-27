class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long int totalSum=0;
        for(int i=0;i<nums.size();i++){
            totalSum+=nums[i];
        }
        long long sum=0;
        int cnt=0;
        for(int i=0;i<nums.size()-1;i++){
            sum+=nums[i];
            if(sum>=(totalSum-sum)){
                cnt++;
            }

        }
        return cnt;
    }
};