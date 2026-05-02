class Solution {
public:
    bool good(int n){
        bool changed=false;
        while(n>0){
            int d=n%10;
            if(d==3 || d==7 || d==4)return false;
            if(d==2 || d==5 || d==6 || d==9)changed=true;
            n=n/10;

        }
        return changed;
    }
    int rotatedDigits(int n) {
        int cnt=0;
        for(int i=0;i<=n;i++){
            if(good(i))cnt++;
        }
        return cnt;
    }
};