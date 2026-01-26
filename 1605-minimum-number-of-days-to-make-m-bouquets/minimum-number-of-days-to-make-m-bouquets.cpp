class Solution {
public:
    bool fun(vector<int>& arr, int day,int k,int m){
        int cnt=0;
        int noofbook=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]<=day){
                cnt++;
            }else{
                noofbook+=(cnt/k);
                cnt=0;
            }
        }
        noofbook+=(cnt/k);
        if(noofbook>=m)return true;
        else return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int high=*max_element(bloomDay.begin(),bloomDay.end());
        int low=*min_element(bloomDay.begin(),bloomDay.end());
        if(bloomDay.size()/k<m)return -1;
        int ans=INT_MAX;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(fun(bloomDay,mid,k,m)){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};