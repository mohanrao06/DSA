class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;
        vector<bool> flag(n,true);
        flag[0]=false;
        flag[1]=false;
        int cnt=0;
        for(int i=2;i<n;i++){
            if(flag[i]){
                cnt++;
                for(int j=2*i;j<n;j+=i){
                    flag[j]=0;
                }

            }
        }
        return cnt;
    }
};