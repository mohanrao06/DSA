class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int>temp=nums;
        for(int i=0;i<nums.size();i++){
            temp.push_back(nums[i]);

        }
        return temp;
    }
};