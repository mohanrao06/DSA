class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int  i=0;
        int j=nums.size()-1;
        vector<double> ans;
        while(i<j){
            double a=(nums[i]+nums[j])/(2.0);
            ans.push_back(a);
            i++;
            j--;
        
        }
        double mini=ans[0];
        for(int i=1;i<ans.size();i++){
            if(mini>ans[i]){
                mini=ans[i];
            }
        }
        // return mini;
        return mini;
    }
};