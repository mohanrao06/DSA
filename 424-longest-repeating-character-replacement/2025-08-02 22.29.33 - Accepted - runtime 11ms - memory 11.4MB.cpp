class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0;
        int r=0;
        map<char,int> mp;
        int n=s.size();
        int ans=0;
        int mf=0;
        while(r<n){
            mp[s[r]]++;
            mf=max(mf,mp[s[r]]);
            int len=r-l+1;
            if(len-mf>k){
                mp[s[l]]--;
                if(mp[s[l]]==0)mp.erase(s[l]);
                else{
                    mf=max(mf,mp[s[l]]);
                }
                l++;
            }
            if(len-mf<=k){
                ans=max(ans,r-l+1);
            }
            r++;
            

        }
        return ans;
    }
};