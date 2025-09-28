class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int na=nums.size();
        unordered_map<int,int> numMap;
        for(int i=0;i<na;i++){
            int rem=target-nums[i];
            if(numMap.count(rem)){
                return {numMap[rem],i};
            }
            numMap[nums[i]]=i;
        }
        return {};
    }
};