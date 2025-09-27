class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(),intervals.end());
        int  pr=intervals[0][1];
        int cnt=0;
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<pr){
                cnt++;
                pr=min(pr,intervals[i][1]);
                
            }else{
                pr=intervals[i][1];
            }
        }
        return cnt;
    }
};