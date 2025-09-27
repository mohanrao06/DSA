class Solution {
public:

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        if(intervals.size()==0){
            return ans;
        }
        

        sort(intervals.begin(),intervals.end());
        pair<int,int> pr={intervals[0][0],intervals[0][1]};
        for(int i=1;i<intervals.size();i++){
            if(pr.second>=intervals[i][0]){
                pr.second=max(pr.second,intervals[i][1]);
            }else{
                ans.push_back({pr.first,pr.second});
                pr={intervals[i][0],intervals[i][1]};

            }
            
            
        }
        ans.push_back({pr.first,pr.second});
        
        return ans;
    }
};