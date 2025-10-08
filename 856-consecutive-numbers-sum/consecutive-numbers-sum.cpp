class Solution {
public:
    int consecutiveNumbersSum(int n) {
        int res = 0;
        for (int k = 1; (k * (k + 1) / 2) <= n; k++) {
            if (2 * n % k != 0) 
                continue;
            int term = ((2 * n) / k) - k + 1.;
            if (term % 2 == 0 && term > 0)
                res++;
        }
        return res;
    }
};