class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        if (nums.empty()) return 0;
        sort(nums.begin(),nums.end());
        int last_ele=INT_MIN;

        int max_cnt=1;
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]-1==last_ele){
                last_ele=nums[i];
                cnt++;

            }else if(nums[i]!=last_ele){
                cnt=1;
                last_ele=nums[i];


            }
            max_cnt=max(max_cnt,cnt);
        }
        

        
        return max_cnt;
    }
};