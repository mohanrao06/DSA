class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int lsum=0;
        int rsum=0;
        int ans=0;
        for(int i=0;i<k;i++){
            lsum+=cardPoints[i];
        }
        ans=lsum;
        int rind=cardPoints.size()-1;
        for(int i=k-1;i>=0;i--){
            lsum-=cardPoints[i];
            rsum+=cardPoints[rind];
            rind=rind-1;
            ans=max(ans,lsum+rsum);

        }
        return ans;
    }
};