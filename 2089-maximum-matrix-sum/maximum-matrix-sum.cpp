class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int smallest=INT_MAX;
        long long sum=0;
        int cnt=0;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix.size();j++){
                sum+=abs(matrix[i][j]);
                if(matrix[i][j]<0){
                    cnt++;
                }
                smallest=min(smallest,abs(matrix[i][j]));

            }
        }
        if(cnt%2==0)return sum;
        return sum-2*smallest;
    }
};