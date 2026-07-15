class Solution {
public:
    int gcd(int a, int b) {
    return (b == 0) ? a : gcd(b, a % b);
}
    int gcdOfOddEvenSums(int n) {
        int evenSum=n*(n+1);
        int oddSum=n*n;
        return gcd(evenSum,oddSum);
    }
};