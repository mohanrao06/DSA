class Solution {
public:
    string processStr(string s) {
        int n=s.size();
        string str;
        for(int i=0;i<n;i++){
            char ch=s[i];
            if(ch=='*'){
                if(str.size()>=1)
                str.pop_back();
            }
            else if(ch=='#'){
                str+=str;
            }
            else if(ch=='%'){
                reverse(str.begin(),str.end());
            }else{
                str.push_back(ch);
            }
        }
        return str;
    }
};