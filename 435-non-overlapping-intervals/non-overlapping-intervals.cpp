class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int n=intervals.size();
        int start=intervals[0][0];
        int end=intervals[0][1];
        int cnt=0;
        for(int i=1;i<n;i++){
            if(end>intervals[i][0]){
                end=min(end,intervals[i][1]);
                cnt++;
            }else{
                start=intervals[i][0];
                end=intervals[i][1];
            }
        }
        return cnt;
    }
};