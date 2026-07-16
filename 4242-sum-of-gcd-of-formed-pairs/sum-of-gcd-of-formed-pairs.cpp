class Solution {
public:
    int GCD(int x,int y){
        return y==0?x:GCD(y,x%y);
    }
    long long gcdSum(vector<int>& nums) {
        int n=nums.size();
        vector<int> arr;
        arr.push_back(nums[0]);
        int mx=nums[0];
        int gcd=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]>=mx){
                mx=nums[i];
                gcd=nums[i];
            }else{
                gcd=GCD(nums[i],mx);
                
            }
            arr.push_back(gcd);
        }
        sort(arr.begin(),arr.end());
        int l=0;
        int r=arr.size()-1;
        long long sum=0;
        while(l<r){
            sum+=GCD(arr[l],arr[r]);
            l++;
            r--;
        }
        return sum;


    }
};