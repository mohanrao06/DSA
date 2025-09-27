class Solution {
public:
    string findCommonResponse(vector<vector<string>>& responses) {
        map<string, int> freq_map;
        for(int i=0;i<responses.size();i++){
            set<string> unique_responses;
            for (string &response : responses[i]) {
                unique_responses.insert(response);  // remove duplicates within a day
            }
            for (auto response : unique_responses) {
                freq_map[response]++;
            }
        }
        string res;
        int max_freq = 0;
        for (auto &it : freq_map) {
            if (it.second > max_freq) {
                max_freq = it.second;
                res = it.first;
            } else if (it.second == max_freq) {
                res = min(res, it.first); // lexicographically smaller
            }
        }
        
        return res;
    }
};