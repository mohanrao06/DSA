class Solution {
public:
    int rob1(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+2,0);
        int next=0;
        int next2=0;
        for(int i=n-1;i>=0;i--){
            int nottake=next;
            int take=nums[i]+next2;
            int curr=max(take,nottake);
            next2=next;
            next=curr;

        }
        return next;
    }
    int rob(vector<int>& nums) {
        vector<int> temp1;
        vector<int> temp2;
        if(nums.size()==1)return nums[0];
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(i!=0)temp1.push_back(nums[i]);
            if(i!=n-1)temp2.push_back(nums[i]);
        }
        return max(rob1(temp1),rob1(temp2));

    }
};