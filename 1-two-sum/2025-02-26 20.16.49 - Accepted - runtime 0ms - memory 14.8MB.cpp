class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        unordered_map<int,int> numMap;
        for(int i=0;i<n;i++){
            int rem=target-nums[i];
            if(numMap.count(rem)){
                return {numMap[rem],i};
            }
            numMap[nums[i]]=i;
        }
        return {};
    }
};