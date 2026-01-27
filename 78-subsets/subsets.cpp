class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int n=nums.size();
        for(int mask=0;mask<(1<<n);mask++){
            vector<int> temp;
            for(int bit=0;bit<n;bit++){
                if(mask & (1<<bit)){
                    temp.push_back(nums[bit]);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
