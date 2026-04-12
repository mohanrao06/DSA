class Solution {
public:
    int dp[300][27][27];
    pair<int,int> cord(int curr){
        return {curr/6, curr%6};
        
    }
    int getdist(string word,int ind,int f){
        if(f == 26) return 0;
        int curr = word[ind]-'A';
        auto [x1, y1] = cord(curr);
        auto [x2, y2] = cord(f);
        return abs(x1-x2) + abs(y1-y2);
    }
    int slove(string word,int ind,int f1,int f2){
        if(ind>=word.size())return 0;
        if(dp[ind][f1][f2]!=-1)return dp[ind][f1][f2];
        int curr=word[ind]-'A';
        if(f1==26 && f2==26){
            return dp[ind][f1][f2]=0+slove(word,ind+1,curr,f2);
            
        }
        if(f2==26){
            int movef1=getdist(word,ind,f1)+slove(word,ind+1,curr,f2);
            int movef2=0+slove(word,ind+1,f1,curr);
            return dp[ind][f1][f2]=min(movef1,movef2);
        }
        int movef1=getdist(word,ind,f1)+slove(word,ind+1,curr,f2);
        int movef2=getdist(word,ind,f2)+slove(word,ind+1,f1,curr);
        return dp[ind][f1][f2]=min(movef1,movef2);
    }
    int minimumDistance(string word) {
        memset(dp, -1, sizeof(dp));
        return slove(word,0,26,26);
    }
};