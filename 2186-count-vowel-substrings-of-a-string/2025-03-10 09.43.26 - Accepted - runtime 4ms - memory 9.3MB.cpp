class Solution {
public:
    bool isVowel(char c){
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }
    int countVowelSubstrings(string word) {
        int cnt=0;
        

        for(int i=0;i<word.size();i++){
            set<char> set;
            for(int j=i;j<word.size();j++){
                if(!isVowel(word[j])){
                   break;

                }
                set.insert(word[j]);
                if(set.size()>=5)cnt++;

            }
        

        }
        return cnt;
    }
};