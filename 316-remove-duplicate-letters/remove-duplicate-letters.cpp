class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> vis(26,0);
        vector<int> lastOcc(26,0);
        for(int i=0;i<s.size();i++){
            lastOcc[s[i]-'a']=i;
        }
        string ans="";
        for(int i=0;i<s.size();i++){
            char curr=s[i];
            int idx=curr-'a';
            if(vis[idx])continue;

            while(!ans.empty() && ans.back()>curr && lastOcc[ans.back()-'a']>i){
                vis[ans.back()-'a']=0;
                ans.pop_back();
            }

            ans.push_back(curr);
            vis[idx]=1;
        }
        return ans;
    }
};