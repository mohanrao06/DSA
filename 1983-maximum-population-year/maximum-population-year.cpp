class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int> arr(2051,0);
        vector<pair<int,int>> sweep;
        for(int i=0;i<logs.size();i++){
            int st=logs[i][0];
            int end=logs[i][1];
            sweep.push_back({st,+1});
            sweep.push_back({end,-1});
        }
        sort(sweep.begin(),sweep.end());

        int maxi=0;
        int ans=1950;
        int sum=0;
        for(int i=0;i<sweep.size();i++){
            sum+=sweep[i].second;
            if(sum>maxi){
                maxi=sum;
                ans=sweep[i].first;
            }
        }
        return ans;

    }
};