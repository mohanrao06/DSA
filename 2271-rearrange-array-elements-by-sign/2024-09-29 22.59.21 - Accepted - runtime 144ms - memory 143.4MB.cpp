class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans;
        vector<int> ans2;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
                ans.push_back(nums[i]);
            }else{
                ans2.push_back(nums[i]);
            }
        }
        vector<int>total;
        int k=0;
        int j=0;
        while(k<ans.size() && j<ans2.size()){
            total.push_back(ans[k]);
            total.push_back(ans2[j]);
            k++;
            j++;

        }
        return total;
        // return total;
        
        
    }
};