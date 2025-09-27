class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size()) return false;
        string text = s + s;
        return text.find(goal) != string::npos;
    }
};