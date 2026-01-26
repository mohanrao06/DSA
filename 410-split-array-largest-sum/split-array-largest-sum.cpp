class Solution {
public:
    int fun(vector<int>& arr, int mid){
        int noOfsubarr=1;
        int sum=0;
        for(int i=0;i<arr.size();i++){
            if(sum+arr[i]>mid){
                noOfsubarr++;
                sum=arr[i];

            }else{
                sum+=arr[i];
            }
        }
        return noOfsubarr;
    }
    int splitArray(vector<int>& nums, int k) {
        int low=*max_element(nums.begin(),nums.end());
        int high=0;
        for(int i=0;i<nums.size();i++){
            high+=nums[i];
        }
        int  ans=0;
        while(low<=high){
            int mid=(low+high)/2;
            if(fun(nums,mid)<=k){
                ans=mid;
                high=mid-1;
                
            }else{
               low=mid+1;
            }
        }
        return ans;
    }
};