class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int> ans ;

        int n = nums.size() ;

        int count = 0, lesser = 0 ;

        for(int i=0; i<n; i++){
            if(nums[i] < target) lesser++ ;
            else if(nums[i] == target) count++ ;
        }

        int start = lesser, end = start + count - 1 ;
        for(int i=start; i<=end; i++){
            ans.push_back(i) ;
        }

        return ans ;
    }
    
};