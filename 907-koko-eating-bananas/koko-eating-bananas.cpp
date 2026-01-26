class Solution {
public:
    long long fun(vector<int>& arr, int k){
        long long hours=0;
        for(int i=0;i<arr.size();i++){
            hours += (arr[i] + k - 1) / k;
        }
        return hours;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi=*max_element(piles.begin(),piles.end());
        int low=1;
        int high=maxi;
        int ans=INT_MAX;
        while(low<=high){
            int mid=(low+high)/2;
            long long th=fun(piles,mid);
            if(th<=h){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }

        }
        return ans;
    }
};