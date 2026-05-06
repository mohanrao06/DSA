class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int n=boxGrid.size();
        int m=boxGrid[0].size();
        vector<vector<char>> arr(m,vector<char>(n));
        //transpose 
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                arr[j][i]=boxGrid[i][j];
                // arr[j][i]=boxGrid[j][i];
            }
        }
        for(int i=0;i<m;i++){
            reverse(arr[i].begin(),arr[i].end());
        }
        for(int i=0;i<n;i++){
            int emp=m-1;
            for(int j=m-1;j>=0;j--){
                if(arr[j][i]=='*'){
                    emp = j - 1;
                }
                if(arr[j][i]=='#'){
                    swap(arr[j][i],arr[emp][i]);
                    emp--;
                }
            }
        }
        return arr;


    }
};