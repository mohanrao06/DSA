class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> n;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            while(i+1<nums.size()&&nums[i]==nums[i+1]){
                n.push_back(nums[i]);
                i++;
            }
        }
        return n;
        
    }
};