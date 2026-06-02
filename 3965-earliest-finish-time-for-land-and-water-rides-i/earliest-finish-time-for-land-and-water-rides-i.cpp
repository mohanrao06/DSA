class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int minTime = INT_MAX;
    for (int i = 0; i < landStartTime.size(); ++i) {
        for (int j = 0; j < waterStartTime.size(); ++j) {
            // Case 1: Land ride first
            int startL = landStartTime[i];
            int endL = startL + landDuration[i];
            int startW = max(endL, waterStartTime[j]);
            int endW = startW + waterDuration[j];
            minTime = min(minTime, endW);

            // Case 2: Water ride first
            startW = waterStartTime[j];
            endW = startW + waterDuration[j];
            startL = max(endW, landStartTime[i]);
            endL = startL + landDuration[i];
            minTime = min(minTime, endL);
        }
    }
    return minTime;
    }
};