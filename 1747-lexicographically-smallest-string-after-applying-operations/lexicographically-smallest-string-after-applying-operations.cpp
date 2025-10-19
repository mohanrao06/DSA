class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        queue<string> q;
        unordered_set<string> vis;
        q.push(s);
        vis.insert(s);
        string result=s;
        while(!q.empty()){
            string curr=q.front();
            q.pop();
            result=min(result,curr);

            // add operatiomm 
            string add_s=curr;
            for(int i=1;i<add_s.length();i=i+2){
                add_s[i]=((add_s[i]-'0'+a)%10)+'0';
            }
            if(vis.find(add_s)==vis.end()){
                vis.insert(add_s);
                q.push(add_s);
            }

            // rotate operation 

            string rotate_s=curr;
            int n=curr.length();
            rotate(rotate_s.begin(),rotate_s.begin()+n-b,rotate_s.end());
            if(vis.find(rotate_s)==vis.end()){
                vis.insert(rotate_s);
                q.push(rotate_s);
            }
        }
        return result;
    }
};