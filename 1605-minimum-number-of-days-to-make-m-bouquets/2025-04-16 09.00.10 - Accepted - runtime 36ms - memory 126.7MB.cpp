class Solution {
public:
    bool isPossible(vector<int> arr,int day,int m,int k){
        int cnt=0;
        int noOfBook=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]<=day){
                cnt++;
            }else{
                noOfBook+=(cnt/k);
                cnt=0;
            }
        }
        noOfBook+=(cnt/k);
        if(noOfBook>=m)return true;
        else return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int low=*min_element(bloomDay.begin(),bloomDay.end());
        int high=*max_element(bloomDay.begin(),bloomDay.end());
        int size=bloomDay.size();
        while(low<=high){
            int mid=low+(high-low)/2;
            if(isPossible(bloomDay,mid,m,k)){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        if(size/k<m)return -1;
        else{
            return low;
        }
    }
};