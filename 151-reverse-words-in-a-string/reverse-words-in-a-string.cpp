class Solution {
public:
    string reverseWords(string s) {
        string temp=s;
        reverse(temp.begin(),temp.end());
        string ans="";
        for(int i=0;i<temp.size();i++){
            string word="";
            while(i<temp.size() && temp[i]!=' '){
                word+=temp[i];
                i++;
            }
            reverse(word.begin(),word.end());
            if(word.length()>0)ans+=" "+word;

        }
        return ans.substr(1);
    }
};