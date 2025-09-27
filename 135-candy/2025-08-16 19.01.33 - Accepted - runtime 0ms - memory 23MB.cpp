class Solution {
public:
    int candy(vector<int>& arr) {

        int n=arr.size();
        vector<int> left(n);
        left[0]=1;
        for(int i=1;i<n;i++){
            if(arr[i]>arr[i-1]){
                left[i]=left[i-1]+1;
            }else{
                left[i]=1;
            }
        }
        int curr=1;
        int right=1;
        int ans=max(1,left[n-1]);
        for(int i=n-2;i>=0;i--){
            if(arr[i]>arr[i+1]){
                right++;
            }else{
                right=1;
            }
            ans+=max(left[i],right);
        }
        return ans;
    }
};