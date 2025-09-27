class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> less;
        vector<int> more;
        vector<int> eq;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]>pivot){
                more.push_back(nums[i]);
            }else if(nums[i]<pivot){
                less.push_back(nums[i]);
            }else{
                eq.push_back(nums[i]);
            }
        }
        int j=0;
        for(int i=j;i<less.size();i++){
            nums[j]=less[i];
            j++;
        }
        
        for(int i=0;i<eq.size();i++){
            nums[j]=eq[i];
            j++;
        }
        for(int i=0;i<more.size();i++){
            nums[j]=more[i];
            j++;
        }
        return nums;

        

    }
};