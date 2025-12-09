class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        int mod=1000000007;
        long long  ans=0;
        int n=nums.size();
        map<int,int> prev;
        map<int,int> next;
        for(int it:nums)next[it]++;
        for(int j=0;j<n;j++){
           next[nums[j]]--;
           int sq=nums[j]*2;
            if (prev.count(sq) && next.count(sq)) {
                ans = (ans + 1LL*prev[sq] * next[sq]) % mod;
            }
            prev[nums[j]]++;

        }
        




        return ans;
    }
};