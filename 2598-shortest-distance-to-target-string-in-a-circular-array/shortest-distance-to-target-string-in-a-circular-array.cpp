class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int ans=INT_MAX;
        int n=words.size();
        unordered_map<string,vector<int>> mp;
        for(int i=0;i<n;i++){
            mp[words[i]].push_back(i);
        }
        if(mp.find(target)!=mp.end()){
            vector<int> vec=mp[target];
            for(auto i:vec){
                int right=(i-startIndex+n)%n;
                int left=(startIndex-i+n)%n;
                ans=min(ans,min(left,right));
            }
        }
        if(ans==INT_MAX)return -1;
        return ans;

    }
};