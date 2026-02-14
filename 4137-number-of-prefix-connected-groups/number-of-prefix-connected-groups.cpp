class Solution {
public:
    int prefixConnected(vector<string>& words, int k) {
        unordered_map<string,int> mp;
        for(int i=0;i<words.size();i++){
            if(words[i].size()<k)continue;
            string str=words[i].substr(0,k);
            mp[str]++;
        }
        int cnt=0;
        for(auto it:mp){
            if(it.second>=2){
                cnt++;
            }
        }
        return cnt;

    }
};