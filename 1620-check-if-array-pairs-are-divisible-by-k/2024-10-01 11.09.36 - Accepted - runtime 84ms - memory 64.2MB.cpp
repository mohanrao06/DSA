class Solution {
public:
    
    bool canArrange(vector<int>& arr, int k) {
        vector<int> remainderCount(k, 0);

        // Step 1: Count the remainders
        for (int num : arr) {
            int rem = ((num % k) + k) % k;  // Ensure the remainder is non-negative
            remainderCount[rem]++;
        }

        // Step 2: Check if we can form valid pairs
        for (int i = 1; i < k; i++) {
            // For each i, remainderCount[i] must equal remainderCount[k - i]
            if (remainderCount[i] != remainderCount[k - i]) {
                return false;
            }
        }

        // Special case: remainder 0 needs to have an even count
        if (remainderCount[0] % 2 != 0) {
            return false;
        }

        return true;
    }


};