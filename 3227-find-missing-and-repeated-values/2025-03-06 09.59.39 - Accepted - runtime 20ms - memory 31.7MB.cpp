class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int> ans;
        unordered_map<int,int> mp;
        int size=pow(grid.size(),2);
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                mp[grid[i][j]]++;
            }
        }
        int sum=0;
        for(auto it:mp){
            sum+=it.first;

            if(it.second==2){
                ans.push_back(it.first);
            }
        }
        int miss=(size*(size+1)/2)-sum;
        ans.push_back(miss);

        return ans;


    }
};