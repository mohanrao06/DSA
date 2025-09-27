class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> ans1;
        for(int i=0;i<s.size();i++){
           if(s[i]!='#'){
            ans1.push(s[i]);
           }else{
            if(ans1.empty()){
                continue;
            }else{
                ans1.pop();
            }  
           }         
        }
        stack<char> ans2;
        for(int i=0;i<t.size();i++){
           if(t[i]!='#'){
            ans2.push(t[i]);
           }else{
            if(ans2.empty()){
                continue;
            }else{
                ans2.pop();
            }
           }
        }

        
        return ans1==ans2;

        
    }
};