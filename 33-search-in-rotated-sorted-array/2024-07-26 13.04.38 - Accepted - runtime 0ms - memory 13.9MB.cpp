class Solution {
public:
    int getPivot(vector<int>& nums){
    int s=0;
    int e=nums.size()-1;
    int mid=s+((e-s)/2);
    while(s<e){
        if(nums[mid]>=nums[0]){
            s=mid+1;
        }else{
            e=mid;
        }
        mid=s+((e-s)/2);
    }
    return s;
    }
    int binarySearch(vector<int>& nums,int s,int n,int key){
    int start=s;
    int end=n;
    

    int mid=start+((end-start)/2);

    while(start<=end){
        if(nums[mid]==key){
            return mid;
        }if(key>nums[mid]){
            start=mid+1;

        }else{
            end=mid-1;;
        }
        mid=start+((end-start)/2);

    
    }
    return -1;
}


    int search(vector<int>& nums, int target) {
        int n=nums.size()-1;
        int pio=getPivot(nums);
        if(target>=nums[pio]&& target<=nums[n]){
            return binarySearch(nums,pio,n,target);
        }
        else{
            return binarySearch(nums,0,pio-1,target);
        }
         
    }
};