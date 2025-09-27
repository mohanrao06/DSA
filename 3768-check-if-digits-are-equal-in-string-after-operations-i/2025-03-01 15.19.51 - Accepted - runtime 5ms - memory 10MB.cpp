class Solution {
public:
    bool hasSameDigits(string s) {
        while (s.size() > 2) {
            string new_s = "";
            for (int i = 0; i < s.size() - 1; i++) {
                int num1 = s[i] - '0';
                int num2 = s[i + 1] - '0';
                new_s += (num1 + num2) % 10 + '0';  // Convert back to character
            }
            s = new_s;
        }
        return s[0] == s[1];
    }
};