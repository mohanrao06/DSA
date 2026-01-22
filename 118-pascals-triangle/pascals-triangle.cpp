class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i=1;i<=numRows;i++){
            vector<int> list;
            if(i==1){
                list.push_back(1);
                ans.push_back(list);
                continue;
            }
            int prev=0;
            for(int j: ans.back()){
                list.push_back(prev+j);
                prev=j;
            }
            list.push_back(prev);
            ans.push_back(list);
        }
        return ans;
    }
};