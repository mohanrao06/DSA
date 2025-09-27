class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> arr;
        
         for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                arr.push_back(grid[i][j]);
                
            }
        }
        sort(arr.begin(),arr.end());
        for (int val : arr) {
            if (abs(val - arr[0]) % x != 0) {
                return -1;
            }
        }
        int median=arr[arr.size()/2];
        int ans=0;
        for(int val:arr){
            ans+=abs(val-median)/x;

        }
        return ans;
        
    }
};