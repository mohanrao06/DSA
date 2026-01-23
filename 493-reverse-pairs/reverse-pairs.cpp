class Solution {
public:
    int  cnt=0;
    void mergesort(vector<int> &nums,int low,int mid,int high){
        vector<int> temp;
        int left=low;
        int right=mid+1;
        while(left<=mid && right<=high){
            if(nums[left]>nums[right]){
                temp.push_back(nums[right]);
                right++;
            }else{
                temp.push_back(nums[left]);
                
                left++;
            }
        }
        while(left<=mid){
            temp.push_back(nums[left]);
            left++;
        }
        while(right<=high){
            temp.push_back(nums[right]);
            right++;
        }
        
        for(int i=low;i<=high;i++){
            nums[i]=temp[i-low];
        }
    }
    void countPairs(vector<int> &nums,int low,int mid,int high){
        int right=mid+1;
        for(int i=low;i<=mid;i++){
            while(right<=high && 2LL*nums[right]<nums[i]){
                right++;
            }
            cnt+=(right-(mid+1));
        }
    }
    void merge(vector<int> &nums,int low,int high){
        if(low>=high){
            return;
        }
        int mid=(low+high)/2;
        merge(nums,low,mid);
        merge(nums,mid+1,high);
        countPairs(nums,low,mid,high);
        mergesort(nums,low,mid,high);
    }
    int reversePairs(vector<int>& nums) {
        cnt=0;
        int n=nums.size();
        cnt=0;
        
        merge(nums,0,n-1);
        return cnt;
    }
};