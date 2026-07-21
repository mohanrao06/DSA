class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n=s.size();
        int ans=count(s.begin(),s.end(),'1');
        vector<int> zeroBlocks;
        int i=0;
        while(i<n){
            if(s[i]=='0'){
                int start=i;
                while(i<n && s[i]=='0'){
                    i++;
                }
                zeroBlocks.push_back(i-start);

            }else{
                i++;
            }
        }
        int maxPair=0;
        for(int i=1;i<zeroBlocks.size();i++){
            maxPair=max(maxPair,zeroBlocks[i-1]+zeroBlocks[i]);
        }
        return ans+maxPair;
    }
};