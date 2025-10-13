class Solution {
public:
    vector<int> freq(string s){
        vector<int> ans(26);
        for(int i=0;i<s.size();i++){
            ans[s[i]-'a']++;
        }
        return ans;
    }
    bool check(vector<int> s1,vector<int> s2){
        for(int i=0;i<26;i++){
            if(s1[i]!=s2[i])return false;

        }
        return true;
    }
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans;
        ans.push_back(words[0]);
        vector<int> currfreq=freq(ans[0]);
        for(int i=1;i<words.size();i++){
            vector<int> tempfreq=freq(words[i]);
            if(!check(currfreq,tempfreq)){
                ans.push_back(words[i]);
                currfreq=tempfreq;
            }

        }
        return ans;

    }
};