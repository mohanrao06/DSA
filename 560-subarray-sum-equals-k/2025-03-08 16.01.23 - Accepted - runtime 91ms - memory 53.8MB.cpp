class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int> preSum;
        int cnt=0;
        int sum=0;
        preSum[0]=1;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            int rem=sum-k;
            cnt+=preSum[rem];
            preSum[sum]+=1;
            
        }
        return cnt;
    }
};