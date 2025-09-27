class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans;
        long long temp=1;
        ans.push_back(1);
        for(int col=1;col<=rowIndex;col++){
            temp=temp*(rowIndex-col+1);
            temp=temp/col;
            ans.push_back(temp);
        }
        return ans;
    }
};