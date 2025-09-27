#include <vector>

class Solution {
public:
    bool isTrionic(std::vector<int>& nums) {
        int n = nums.size();

        for (int p = 1; p < n - 2; ++p) {
            for (int q = p + 1; q < n - 1; ++q) {
                
                bool is_part1_valid = true;
                for (int i = 0; i < p; ++i) {
                    if (nums[i] >= nums[i + 1]) {
                        is_part1_valid = false;
                        break;
                    }
                }
                
                if (!is_part1_valid) {
                    continue;
                }

                bool is_part2_valid = true;
                for (int i = p; i < q; ++i) {
                    if (nums[i] <= nums[i + 1]) {
                        is_part2_valid = false;
                        break;
                    }
                }
                
                if (!is_part2_valid) {
                    continue;
                }

                bool is_part3_valid = true;
                for (int i = q; i < n - 1; ++i) {
                    if (nums[i] >= nums[i + 1]) {
                        is_part3_valid = false;
                        break;
                    }
                }
                
                if (is_part3_valid) {
                    return true;
                }
            }
        }
        
        return false;
    }
};
        
