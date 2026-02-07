class Solution {
public:
    int minimumDeletions(string s) {
        int cnta=0;
        int cntb=0;
        int n=s.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            if(s[i]=='a'){
                if(cntb>0){
                    cntb--;
                    cnt++;
                }
                cnta++;
            }else{
                cntb++;
            }
        }
        return cnt;

    }
};