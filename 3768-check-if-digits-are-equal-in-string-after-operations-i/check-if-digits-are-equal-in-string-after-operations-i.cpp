class Solution {
public:
    bool hasSameDigits(string s) {

        
       while(s.size()>2){
            string temp;
            for(int  i=0;i<s.size()-1;i++){
                int first=s[i]-'0';
                int sec=s[i+1]-'0';
                int newd=(first+sec)%10;
                temp.push_back(newd+'0');
            }
            s=temp;
       }
       return s[0]==s[1];
    }
};