class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        int n=nums.size();
        for(int i=0;i<n;i++){
            string num=to_string(nums[i]);
            for(char ch:num){
                ans.push_back( ch - '0');
            }
            
        }
        return ans;
    }
};