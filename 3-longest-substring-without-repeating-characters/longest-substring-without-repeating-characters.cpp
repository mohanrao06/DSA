class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans=0;
        int l=0;
        int n=s.size();
        vector<int> hash(256,-1);
        for(int r=0;r<n;r++){
            if(hash[s[r]]!=-1){
                if(hash[s[r]]>=l){
                    l=hash[s[r]]+1;
                }
            }
            
            ans=max(ans,r-l+1);
            hash[s[r]]=r;
        }
        return ans;
    }
};