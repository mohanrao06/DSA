class Solution {
public:
    int countOdds(int low, int high) {
        int ans = 0;
        bool lowOdd = low & 1;
        bool highOdd = high & 1;

        if (lowOdd && highOdd) {
            ans = (high - low) / 2;
        }
        else if (lowOdd && !highOdd) {
            ans = ((high - 1) - low) / 2;
        }
        else if (!lowOdd && highOdd) {
            ans = (high - (low + 1)) / 2;
        } else {
            ans = ((high - 1) - (low + 1)) / 2;
        }

        return ans + 1;
    }
};
