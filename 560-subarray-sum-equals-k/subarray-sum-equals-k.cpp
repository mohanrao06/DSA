class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int cnt=0;
        int n=nums.size();
        map<int,int> pre;
        pre[0]=1;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            int rem=sum-k;
            if(pre.find(rem)!=pre.end()){
                cnt+=pre[rem];

            }
            pre[sum]++;
        }
        return cnt;
    }
};