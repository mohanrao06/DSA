class Solution {
public:
    int longestBalanced(string s) {
        int ans=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            unordered_map<char,int> mp;
            int maxfreq=1;
            int dist=0;
            for(int j=i;j<n;j++){
                if(mp[s[j]]==0){
                    dist++;
                }
                mp[s[j]]++;
                int freq=mp[s[j]];
                maxfreq=max(freq,maxfreq);
                int len=max(ans,j-i+1);
                if(len==dist*maxfreq){
                    ans=max(ans,len);
                }
            }
        }
        return ans;
    }
};