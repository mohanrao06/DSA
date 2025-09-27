class Solution {
public:
    int maximum69Number (int num) {
        // int n=num;
        // int pv=0;
        // int curr=-1;
        // while(n!=0){
        //     int rem=n%10;
        //     if(rem==6){
        //         curr=pv;
        //     }
        //     n=n/10;
        //     pv++;
        // }
        // return num+(3*pow(10,curr));

        vector<int> arr;
        while(num!=0){
            int rem=num%10;
            arr.push_back(rem);
            num=num/10;
        }
        reverse(arr.begin(),arr.end());
        for(int i=0;i<arr.size();i++){
            if(arr[i]==6){
                arr[i]=9;
                break;
            }
        }
        int ans=0;
        int size=arr.size();
        int m=size-1;
        for(int i=0;i<size;i++){
            ans+=arr[i]*pow(10,m);
            m--;
        }
        return ans;
    }
};