class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        
        int len=encodedText.size();
        int cols=len/rows;
        vector<vector<char>> arr(rows,vector<char>(cols,'_'));
        int index = 0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                arr[i][j] = encodedText[index++];
            }
        }
        
        string ans="";
        for(int c=0;c<cols;c++){
            int i=0;
            int j=c;
            while(i<rows && j<cols){
                ans+=arr[i][j];
                j++;
                i++;
            }
        }
        while(!ans.empty() && ans.back() == ' ') ans.pop_back();
        return ans;

        
    }
};