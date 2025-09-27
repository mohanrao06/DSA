class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int  i=0;
        int j=nums.size()-1;
        double ans=100;
        while(i<j){
            double a=(nums[i]+nums[j])/(2.0);
            ans=min(ans,a);
            i++;
            j--;
        
        }
        
        // return mini;
        return ans;
    }
};