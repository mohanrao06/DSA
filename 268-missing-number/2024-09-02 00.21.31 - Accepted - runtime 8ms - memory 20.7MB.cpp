class Solution {
public:
    int missingNumber(vector<int>& nums) {
    //     vector<int> ans(nums.size()+1,0);
    //     sort(nums.begin(),nums.end());
    //     for(int i=0;i<nums.size();i++){
    //         ans[nums[i]]++;
    //     }
        
    //     for(int j=0;ans.size();j++){
    //         if(ans[j]==0){
    //             return j;
    //         }
    //     }
    //     return ans[1];
    // }/
    int n=nums.size();
    int sum1=n*(n+1)/2;
    int sum2=0;
    for(int i=0;i<n;i++){
        sum2+=nums[i];
    }
    return sum1-sum2;
    }
};