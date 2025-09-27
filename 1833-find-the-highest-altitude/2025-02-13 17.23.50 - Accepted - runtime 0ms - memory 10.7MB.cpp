class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int app=0;
        int sum=0;
        for(int i=0;i<gain.size();i++){
            sum+=gain[i];
            app=max(app,sum);

        }
        return app;
    }
};