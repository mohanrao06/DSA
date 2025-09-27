class Solution {
public:
    int findmax(vector<int> arr){
        int n=arr.size();
        int max=arr[0];
        for(int i=1;i<n;i++){
            if(max<arr[i]){
                max=arr[i];
            }
        }
        return max;

    }
    long long fun(vector<int> arr,int hrs){
        long long ans=0;
        for(int i=0;i<arr.size();i++){
            ans+=ceil((double)arr[i]/hrs);
        }
        return ans;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1,high=findmax(piles);
        while(low<=high){
            int mid=low+(high-low)/2;
            if(fun(piles,mid)<=h){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return low;
    }
};