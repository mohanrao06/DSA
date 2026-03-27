class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int ans=0;
        int l=0;
        int mf=0;
        map<char,int> mp;
        for(int r=0;r<n;r++){
            mp[s[r]]++;
            mf=max(mf,mp[s[r]]);
            while((r-l+1)-mf>k){
                mp[s[l]]--;
                if(mp[s[l]]==0)mp.erase(s[l]);
                else mf=max(mf,mp[s[l]]);
                l++;
            }
            ans=max(ans,r-l+1);
        }
        
        return ans;
    }
};