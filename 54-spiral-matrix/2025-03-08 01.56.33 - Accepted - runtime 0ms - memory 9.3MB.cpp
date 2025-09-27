class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int> ans;
        int left=0;
        int right=m-1;
        int top=0;
        int bot=n-1;
        while(left<=right && top<=bot){
            for(int i=left;i<=right;i++){
                ans.push_back(matrix[top][i]);
            }
            top++;

            for(int i=top;i<=bot;i++){
                ans.push_back(matrix[i][right]);
            }
            right--;
            if(top<=bot){
                for(int i=right;i>=left;i--){
                    ans.push_back(matrix[bot][i]);
                }
                bot--;
            }
            if(left<=right){
                for(int i=bot;i>=top;i--){
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        return ans;

    }
};