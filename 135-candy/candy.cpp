class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> can(n, 1);

        // Left to Right
        for(int i = 1; i < n; i++){
            if(ratings[i] > ratings[i-1]){
                can[i] = can[i-1] + 1;
            }
        }

        // Right to Left
        for(int i = n-2; i >= 0; i--){
            if(ratings[i] > ratings[i+1]){
                can[i] = max(can[i], can[i+1] + 1);
            }
        }

        int ans = 0;
        for(int x : can) ans += x;

        return ans;
    }
};