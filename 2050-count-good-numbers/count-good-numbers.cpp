class Solution {
public:
    const long long MOD = 1000000007;
    long long pow(long long x,long long n){
        if(n==0)return 1;
        if(n==1)return x%MOD;
        if(n%2==0){
            long long half=pow((x*x)%MOD,n/2);
            return half;

        }
        return (x*pow(x,n-1)) %MOD;

    }
    int countGoodNumbers(long long n) {
        long long oddcnt=0;
        long long evencnt=0;
        
        evencnt=(n+1)/2;
        oddcnt=n/2;
        long long odd=pow(4,oddcnt);
        long long even=pow(5,evencnt);
        return (odd*even)%MOD;
        

    }
};