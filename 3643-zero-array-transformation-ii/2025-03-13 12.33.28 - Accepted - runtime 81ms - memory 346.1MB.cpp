class Solution {
public:
    bool isZeros(vector<int>& nums,vector<vector<int>>& queries,int k){
        int n=nums.size();
        vector<int> diff(n+1,0);
        for(int i=0;i<k;i++){
            int l=queries[i][0];
            int r=queries[i][1];
            int val=queries[i][2];
            diff[l]=diff[l]+val;
            if (r + 1 < n) diff[r + 1] -= val;

        }
        for(int i=1;i<diff.size();i++){
            diff[i]+=diff[i-1];

        }
        for(int i=0;i<n;i++){
            if(nums[i]>diff[i])return false;
        }
        return true;
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        
        int low=0;
        int high=queries.size();
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(isZeros(nums,queries,mid)){
                ans=mid;
                high=mid-1;

            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};