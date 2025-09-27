class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        int n=strs.size()-1;
        string first=strs[0];
        string last=strs[n];
        string ans="";
        for(int i=0;i<first.size();i++){
            if(first[i]!=last[i])break;
            ans+=first[i];

        }
        return ans;

    }
};