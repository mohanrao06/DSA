class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        int N=nums.size();
        vector<int> desc(N,1);
        vector<int> inc(N,1);
        for (int i = 1; i < N; i++) {
            if (nums[i] <= nums[i - 1]) {
                desc[i] = 1 + desc[i - 1];
            }
        }

        for (int i = N - 2; i >= 0; i--) {
            if (nums[i] <= nums[i + 1]) {
                inc[i] = 1 + inc[i + 1];
            }
        }
        vector<int> ans;
        for(int i=k;i<N-k;i++){
            if(desc[i-1]>=k && inc[i+1]>=k){
                ans.push_back(i);
            }
        }
        return ans;
    }
};
