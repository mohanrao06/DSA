class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int size=nums.size();
        vector<int> arr;
        for(int i=0;i<size;i++){
            arr.push_back(nums[nums[i]]);
        }
        return arr;

    }
};