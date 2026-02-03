class Solution {
public:
    vector<string> mp = {
        "", "", "abc", "def", "ghi", "jkl",
        "mno", "pqrs", "tuv", "wxyz"
    };
    void fun(string digits,int ind,vector<string> & ans,string temp){
        if(temp.size()==digits.size()){
            ans.push_back(temp);
            return;
        }
        string letters=mp[digits[ind]-'0'];
        for(char ch:letters){
            temp.push_back(ch);
            fun(digits,ind+1,ans,temp);
            temp.pop_back();
        }
        

    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string temp;
        fun(digits,0,ans,temp);
        return ans;
    }
};