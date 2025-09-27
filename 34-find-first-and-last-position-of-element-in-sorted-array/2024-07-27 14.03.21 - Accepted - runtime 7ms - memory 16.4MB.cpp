class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first1=firstOcc(nums,target);
        int last=lastOcc(nums,target);
        return{first1,last};

        
    }
private:
    int firstOcc(vector<int>& nums,int target){
        int ans=-1;
        int s=0;
        int e=nums.size()-1;
        int mid=s+(e-s)/2;


        while(s<=e){
            int mid=s+(e-s)/2;
            if(nums[mid]==target){
                if(mid==0||nums[mid-1]!=target){
                    ans=mid;
                    break;
                
                }else{
                    e=mid-1;
                }
            }
            else if(nums[mid]<target){
                s=mid+1;
            }else{
                e=mid-1;
            }
            
        }
        return ans;

    }
    int lastOcc(vector<int>& nums,int target){
        int ans1=-1;
        int s=0;
        int e=nums.size()-1;
        


        while(s<=e){
            int mid=s+(e-s)/2;
            if(nums[mid]==target){
                if(mid==nums.size()-1 || nums[mid+1]!=target){
                    ans1=mid;
                    break;
                
                }else{
                    s=mid+1;
                }
            }
            else if(nums[mid]<target){
                s=mid+1;
            }else{
                e=mid-1;
            }
            
        }
        return ans1;

    }

    
};