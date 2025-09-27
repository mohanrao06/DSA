class Solution {
public:
    int fun(vector<int> arr,int mid){
        int subarray=1,sum=0;
        for(int i=0;i<arr.size();i++){
            if(sum+arr[i]<=mid){
                sum+=arr[i];
            }else{
                subarray++;
                sum=arr[i];
            }
        }
        return subarray;
    }
    int splitArray(vector<int>& nums, int k) {
        int low=*max_element(nums.begin(),nums.end());
        int high=0;
        for(int i=0;i<nums.size();i++){
            high+=nums[i];
        }
        while(low<=high){
            int mid=low+(high-low)/2;
            if(fun(nums,mid)>k)low=mid+1;
            else high=mid-1;
        }
        return low;
    }
};