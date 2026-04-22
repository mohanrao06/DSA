class Solution {
public:
    int fun(string word1, string word2){
        int cnt = 0;
        for(int i = 0; i < word1.size(); i++){
            if(word1[i] != word2[i]){
                cnt++;
            }
            if(cnt > 2) return cnt; // optimization
        }
        return cnt;
    }
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        int n=queries.size();
        int m=dictionary.size();
        vector<string> ans;
        for(int i=0;i<n;i++){
            string word=queries[i];
            for(int j=0;j<m;j++){
                int compcnt=fun(word,dictionary[j]);
                if(compcnt<=2){
                    ans.push_back(word);
                    break;
                }
            }
        }
        return ans;
    }
};