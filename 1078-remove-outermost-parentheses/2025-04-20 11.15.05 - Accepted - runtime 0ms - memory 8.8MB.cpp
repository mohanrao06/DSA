class Solution {
public:
    string removeOuterParentheses(string s) {
        int cnt=0;
        string ans="";
        for(auto c:s){
            if(c==')')cnt--;
            if(cnt!=0)ans+=c;
            if(c=='(')cnt++;
            
        }
        return ans;
    }
};