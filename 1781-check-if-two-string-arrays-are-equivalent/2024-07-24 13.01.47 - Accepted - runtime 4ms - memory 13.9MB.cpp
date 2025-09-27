class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string full1="";
        string full2="";
        for(int i=0;i<word1.size();i++){
            full1=full1+word1[i];
        }
        for(int i=0;i<word2.size();i++){
            full2=full2+word2[i];
        }
      
        return full1==full2;
        
    }
};