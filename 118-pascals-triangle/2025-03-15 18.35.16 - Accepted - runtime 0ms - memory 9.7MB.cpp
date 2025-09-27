class Solution {
public:
    vector<int> fun(int row){
        vector<int> res;
        long long ans=1;
        res.push_back(1);
        for(int i=1;i<row;i++){
            ans=ans*(row-i);
            ans=ans/i;
            res.push_back(ans);
        }
        return res;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        for(int i=1;i<=numRows;i++){
            vector<int> temp=fun(i);
            ans.push_back(temp);

        }
        return ans;

    }
};