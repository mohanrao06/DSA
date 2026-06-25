class Solution {
public:
    int countHousePlacements(int n) {
        long long MOD = 1e9 + 7;
        long long p1=2;
        long long p2=3;
        if(n==1)return 4;
        for(int i=3;i<=n;i++){
            long long curr=(p1+p2)%MOD;
            p1=p2;
            p2=curr;
        }
        return (p2*p2)%MOD;

    }
};