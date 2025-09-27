class Solution {
public:
    bool isOk(int mid,vector<int>& candies,long long k){
        long long  cnt=0;
        for(int i=0;i<candies.size();i++){
            cnt+=candies[i]/mid;

        }
        if(cnt>=k){
            return true;
        }else{
            return false;
        }
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int left=1;
        int right=*max_element(candies.begin(),candies.end());
        int ans=0;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(isOk(mid,candies,k)){
                ans=mid;
                left=mid+1;
            }else{
                right=mid-1;
            }
        }
        return ans;
    }
};