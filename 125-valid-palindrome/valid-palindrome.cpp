class Solution {
public:
    bool isPalindrome(std::string s) {
        std::transform(s.begin(), s.end(), s.begin(), ::tolower);
        s.erase(std::remove_if(s.begin(), s.end(), [](char c) { return !isalnum(c); }), s.end());
        if (s.length() < 1) {
            return true;
        }
        return rec(0, s);
    }

private:
    static bool rec(int i, const std::string& s) {
        if (i >= s.length() / 2) {
            return true;
        }
        if (s[i] != s[s.length() - i - 1]) {
            return false;
        }
        return rec(i + 1, s);
    }
};