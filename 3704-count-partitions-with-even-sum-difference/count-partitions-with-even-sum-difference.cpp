class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int ans=0;
        int sum=0;
        for(int i=0;i<nums.size();i++)sum+=nums[i];
        int x=0;
        for(int i=0;i<nums.size()-1;i++){
            x+=nums[i];
            int y=sum-x;
            if((x-y)%2==0)ans++;

        }
        return ans;
        
        

    }
};