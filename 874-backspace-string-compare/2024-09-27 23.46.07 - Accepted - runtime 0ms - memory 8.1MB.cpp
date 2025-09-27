class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> ans1;
        for(int i=0;i<s.size();i++){
           if(s[i]=='#'){
            if(!ans1.empty())
                ans1.pop();
           }
            else
                ans1.push(s[i]);

                   
        }

        stack<char> ans2;
        for(int i=0;i<t.size();i++){
           if(t[i]=='#'){
            if(!ans2.empty())
                ans2.pop();
           }
            else
                ans2.push(t[i]);

                  
        }


        
        
        return ans1==ans2;

        
    }
};