class Solution {
public:
    static bool lambda(vector<int>& task1, vector<int>& task2){
        int diff1=task1[1]-task1[0];
        int diff2=task2[1]-task2[0];
        return diff1>diff2;
    }
    bool possible(vector<vector<int>>& tasks,int mid){
        
        for(int i=0;i<tasks.size();i++){
            if(mid<tasks[i][1])return false;
            mid-=tasks[i][0];
        }
        return true;
    }
    int minimumEffort(vector<vector<int>>& tasks) {
        int n=tasks.size();

        sort(tasks.begin(),tasks.end(),lambda);
        int l=0;
        int r=1e9;
        int ans=INT_MAX;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(possible(tasks,mid)){
                ans=mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return ans;
    }
};