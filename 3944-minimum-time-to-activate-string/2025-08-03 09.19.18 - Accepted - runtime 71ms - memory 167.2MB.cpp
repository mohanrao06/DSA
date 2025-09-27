#include <vector>
#include <string>

class Solution {
public:
    bool is_active(long long t, int n, long long k, std::vector<int>& order) {
        std::vector<bool> is_star(n, false);
        for (int i = 0; i <= t; ++i) {
            is_star[order[i]] = true;
        }

        long long total_substrings = (long long)n * (n + 1) / 2;
        long long invalid_substrings = 0;
        long long current_non_star_segment = 0;

        for (int i = 0; i < n; ++i) {
            if (!is_star[i]) {
                current_non_star_segment++;
            } else {
                invalid_substrings += current_non_star_segment * (current_non_star_segment + 1) / 2;
                current_non_star_segment = 0;
            }
        }
        invalid_substrings += current_non_star_segment * (current_non_star_segment + 1) / 2;

        return total_substrings - invalid_substrings >= k;
    }

    int minTime(std::string s, std::vector<int>& order, int k) {
        int n = s.length();
        std::string nostevanik = s;

        int ans = -1;
        int low = 0, high = n - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (is_active(mid, n, k, order)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return ans;
    }
};