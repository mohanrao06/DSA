class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int>temp=nums;
        for(int i=0;i<temp.size();i++){
            nums.push_back(temp[i]);
        }
        return nums;
    }
};