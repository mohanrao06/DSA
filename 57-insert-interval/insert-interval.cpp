class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        int lastin=intervals[0][0];
        int lastout=intervals[0][1];
        vector<vector<int>> ans;
        for(int i=1;i<n;i++){
            if(lastout>=intervals[i][0]){
                lastout=max(lastout,intervals[i][1]);
            }else{
                ans.push_back({lastin,lastout});
                lastin=intervals[i][0];
                lastout=intervals[i][1];
            }
            
            
        }
        ans.push_back({lastin,lastout});
        return ans;

    }
};