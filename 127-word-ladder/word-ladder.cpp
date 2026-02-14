class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        set<string> st;
        int n=wordList.size();
        for(int i=0;i<n;i++){
            st.insert(wordList[i]);
        }
        while(!q.empty()){
            string word=q.front().first;
            int len=q.front().second;
            q.pop();
            if(word==endWord)return len;
            string temp=word;
            for(int i=0;i<word.size();i++){
                char org=word[i];
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;
                    if(st.count(word)>0){
                        st.erase(word);
                        q.push({word,len+1});
                    }
                }
                word[i]=org;

            }

        }
        return 0;
    }
};