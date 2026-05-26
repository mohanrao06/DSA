class Solution {
public:
    int vowelStrings(vector<string>& words, int left, int right) {
        int n=words.size();
        int cnt=0;
        for(int i=left;i<=right;i++){
            string word=words[i];
            int n=word.size();
            if((word[0]=='a' ||word[0]=='e'||word[0]=='i'||word[0]=='o'||word[0]=='u') && (word[n-1]=='a' ||word[n-1]=='e'||word[n-1]=='i'||word[n-1]=='o'||word[n-1]=='u')){
                cnt++;
            }
        }
        return cnt;
    }
};