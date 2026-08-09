class Solution {
public:
    int maxStones(vector<int>& suffixSum, int M, int ind,vector<vector<int>>& memo){
        if(ind+2*M>=suffixSum.size())return suffixSum[ind];
        if (memo[ind][M] > 0) return memo[ind][M];
        int res=INT_MAX;
        for (int i = 1; i <= 2 * M; ++i) {
            res = min(res, maxStones(suffixSum, max(i, M),
                                     ind + i, memo));
        }
        memo[ind][M] = suffixSum[ind] - res;
        return memo[ind][M];
    }
    int stoneGameII(vector<int>& piles) {
        vector<vector<int>> memo(piles.size(), vector<int>(piles.size()));
        vector<int> suffixSum = piles;
        for (int i = suffixSum.size() - 2; i >= 0; --i)
            suffixSum[i] += suffixSum[i + 1];
        return maxStones(suffixSum, 1, 0, memo);
    }
};