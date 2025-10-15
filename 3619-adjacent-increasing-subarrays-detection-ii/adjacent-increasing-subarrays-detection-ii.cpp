class Solution {
public:
    bool ispossible(vector<int> inc,int k){
        for(int i=0;i<=inc.size()-2*k;i++){
            if(inc[i]>=k && inc[i+k]>=k)return true;
        }
        return false;
    }
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n=nums.size();
        vector<int> inc(n,1);
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                inc[i]=inc[i+1]+1;
            }
        }
        int low=1;
        int high=n/2;
        int ans=0;
        while(low<=high){
            int mid=(low+high)/2;
            if(ispossible(inc,mid)){
                ans=mid;
                low=mid+1;

            }else{
                high=mid-1;
            }
        }
        return ans;
    }
};