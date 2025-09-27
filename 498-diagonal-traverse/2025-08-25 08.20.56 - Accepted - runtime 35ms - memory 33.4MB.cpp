class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> ans;
        map<int,vector<int>> mp;


        for(int row=0;row<mat.size();row++){
            for(int col=0;col<mat[0].size();col++){
                mp[row+col].push_back(mat[row][col]);
            }
        }
        bool flag=true;
        for(auto it:mp){
            if(flag){
                reverse(it.second.begin(),it.second.end());
            }
            for(auto num:it.second){
                ans.push_back(num);
            }
            flag=!flag;

        }
        return ans;
    }
};