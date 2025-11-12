class Solution {
public:
    int minOperations(vector<int>& nums) {
        int count1=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                count1++;
            }
        }
        int n=nums.size();
        if(count1>0){
            return n-count1;
        }
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            int GCD=nums[i];
            for(int j=i+1;j<n;j++){
                GCD=__gcd(GCD,nums[j]);
                if(GCD==1){
                    ans=min(ans,(j-i)+(n-1));
                    break;

                }
            }
        }
        if(ans==INT_MAX)return -1;
        return ans;
    }
};