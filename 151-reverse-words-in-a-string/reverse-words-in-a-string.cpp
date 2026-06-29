class Solution {
public:
    string reverseWords(string s) {
        string temp=s;
        reverse(temp.begin(),temp.end());
        string ans="";
        int n=s.size();
        for(int i=0;i<n;i++){
            string word="";
            while(i<n && temp[i]!=' '){
                word+=temp[i];
                i++;
            }
            reverse(word.begin(),word.end());
            if(word.size()>0)ans+=" "+word;


        }
        return ans.substr(1);
    }
};