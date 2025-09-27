class Solution {
public:
    bool isDigit(char ch){
        return ch>='0' && ch<='9';
    }
    int myAtoi(string s) {
        int len=s.size();
        if(len==0)return 0;
        int idx=0;
        bool isNegtive=false;
        while(idx<len && s[idx]==' '){
            idx++;
        }
        
            if(s[idx]=='-'){
                isNegtive=true;
                idx++;
            }else if(s[idx]=='+'){
                
                idx++;
            }
        
        int result=0;
        while(idx<len && isDigit(s[idx])){
            int digit=s[idx]-'0';
            if(result > (INT_MAX / 10) || (result == (INT_MAX / 10) && digit > 7)){
          return isNegtive ? INT_MIN : INT_MAX;
      }

            result=(result*10)+digit;
            ++idx;
        }
        return isNegtive?-result:result;
    }
};