class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int lsum=0;
        int sum=0;

        for(int i=0;i<k;i++){
            sum+=cardPoints[i];
        }
        lsum=sum;
        int rsum=0;
        int rind=n-1;
        int ans=lsum;
        for(int i=k-1;i>=0;i--){
            lsum-=cardPoints[i];
            rsum+=cardPoints[rind];
            rind--;

            ans=max(ans,lsum+rsum);
        }
        return ans;
    }
};