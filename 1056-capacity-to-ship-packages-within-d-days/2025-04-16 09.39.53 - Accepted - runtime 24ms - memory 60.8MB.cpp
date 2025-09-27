class Solution {
public:
    int fun(vector<int> wt,int cap){
        int day=1,load=0;
        for(int i=0;i<wt.size();i++){
            if(load+wt[i]>cap){
                day++;
                load=wt[i];

            }else{
                load+=wt[i];
            }
        }
        return day;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low=*max_element(weights.begin(),weights.end());
        int high=0;
        for(int i=0;i<weights.size();i++)
        {
            high+=weights[i];
        }
        while(low<=high){
            int mid=low+(high-low)/2;
            if(fun(weights,mid)<=days){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return low;
    }
};