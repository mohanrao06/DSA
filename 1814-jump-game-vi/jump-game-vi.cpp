class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n=nums.size();
        const long long NEG = -4e18;
        deque<int> dq;
        vector<long long> dp(n, NEG);
        dp[n-1]=nums[n-1];
        dq.push_back(n-1);
        for(int ind=n-2;ind>=0;ind--){
            // for(int i=1;i<=k;i++){
            //     if(ind+i<n){
            //         dp[ind]=max(dp[ind],nums[ind]+dp[ind+i]);
            //     }
            // }
            while(!dq.empty() && dq.front()>ind+k){
                dq.pop_front();
            }
            dp[ind]=nums[ind]+dp[dq.front()];
            
            while(!dq.empty() && dp[dq.back()]<=dp[ind]){
                dq.pop_back();
            }
            dq.push_back(ind);
            
        }

        return (int)dp[0];
    }
};