class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int> arr(2051,0);
        for(int i=0;i<logs.size();i++){
            int st=logs[i][0];
            int end=logs[i][1];
            arr[st]++;
            arr[end]--;
        }
        int maxi=0;
        int ans=1950;
        int sum=0;
        for(int i=1950;i<=2050;i++){
            sum+=arr[i];
            if(sum>maxi){
                maxi=sum;
                ans=i;
            }
        }
        return ans;

    }
};