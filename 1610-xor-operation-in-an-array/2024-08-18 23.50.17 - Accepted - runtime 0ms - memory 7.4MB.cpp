class Solution {
public:
    int xorOperation(int n, int start) {
        int sum = 0;
        int nums[n];
        for(int i = 0; i < n; i++){
            nums[i] = start + 2 * i;
            sum ^= nums[i];  // A xor 0 = A
        }
        return sum;
    }
};