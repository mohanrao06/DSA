class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        int m=queries.size();

        int MOD=1000000007;
        vector<int> temp=nums;
        for(int i=0;i<m;i++){
            int l=queries[i][0];
            int r=queries[i][1];
            int k=queries[i][2];
            int v=queries[i][3];

            for(int i=l;i<=r;i+=k){
                temp[i]=(temp[i]*1LL*v)%MOD;
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans=ans^temp[i];
        }
        return ans;
    }
};