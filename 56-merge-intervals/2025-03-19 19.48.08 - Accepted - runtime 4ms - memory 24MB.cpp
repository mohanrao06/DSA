class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end());
        ans.push_back({intervals[0][0],intervals[0][1]});
        
        for(int i=1;i<n;i++){
            int start=intervals[i][0];
            int end=intervals[i][1];
            if(start<=ans.back()[1]){
                ans.back()[1]=max(end,ans.back()[1]);
            }else{
                ans.push_back({intervals[i][0],intervals[i][1]});
            }


        }
        return ans;
    }
};