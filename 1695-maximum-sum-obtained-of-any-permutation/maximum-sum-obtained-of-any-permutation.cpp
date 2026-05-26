class Solution {
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        int n=requests.size();
        int m=nums.size();
        vector<int> diff(m+1,0);
        for(int i=0;i<n;i++){
            int l=requests[i][0];
            int r=requests[i][1];
            diff[l]++;
            diff[r+1]--;
        }
        vector<long long> freq(m);

        freq[0] = diff[0];

        for(int i = 1; i < m; i++) {
            freq[i] = freq[i - 1] + diff[i]; 
        }
        sort(freq.begin(), freq.end(), greater<long long>());
        sort(nums.begin(),nums.end(),greater<int>());

        long long ans = 0;
        long long mod = 1e9 + 7;
        for(int i=0;i<m;i++){
            ans = (ans + (freq[i] * nums[i]) % mod) % mod;
        }

        return ans%1000000007;

    }
};