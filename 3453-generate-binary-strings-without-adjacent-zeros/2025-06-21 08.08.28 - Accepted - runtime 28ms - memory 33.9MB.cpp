class Solution {
public:
    void slove(int n,vector<string> &ans,string temp){
        if(temp.size()==n){
            ans.push_back(temp);
            return;
        }
        temp.push_back('1');
        slove(n,ans,temp);
        temp.pop_back();
        if(temp.empty()||temp.back()!='0'){
            temp.push_back('0');
            slove(n,ans,temp);
        }
    }
    vector<string> validStrings(int n) {
        vector<string> ans;
        string temp;
        slove(n,ans,temp);
        return ans;
    }
};