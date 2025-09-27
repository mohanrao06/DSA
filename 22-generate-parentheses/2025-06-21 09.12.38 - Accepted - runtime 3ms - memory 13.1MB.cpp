class Solution {
public:
    void generate(int n,int open,int close,string &temp,vector<string>& ans){
        if(temp.size()==2*n){
            ans.push_back(temp);
            return;
        }
        if(open<n){
            temp.push_back('(');
            generate(n,open+1,close,temp,ans);
            temp.pop_back();
        }
        if(close<open){
            temp.push_back(')');
            generate(n,open,close+1,temp,ans);
                        temp.pop_back();

        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        int open=0;
        int close=0;
        string temp;
        generate(n,open,close,temp,ans);
        return ans;
    }
};