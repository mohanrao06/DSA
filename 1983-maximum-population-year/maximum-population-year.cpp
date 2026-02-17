class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int> arr(2051,0);
        for(int i=0;i<logs.size();i++){
            int st=logs[i][0];
            int end=logs[i][1];
            for(int j=st;j<end;j++){
                arr[j]++;
            }
        }
        int maxi=0;
        int ans=1950;
        for(int i=1950;i<=2050;i++){
            if(arr[i]>maxi){
                ans=i;
                maxi=arr[i];

            }
        }
        return ans;

    }
};