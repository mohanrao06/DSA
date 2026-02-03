class Solution {
public:
    double fun(double x,long long n){
        if(n==1)return x;
        if(n==0)return 1;
        if(n%2==0){
            return fun(x*x,n/2);
        }
        return x*fun(x,n-1);
    }
    double myPow(double x, int n) {
         long long num=(long long)n;
         if(num<0){
            return (1.0/fun(x,-num));
         }
         return fun(x,num);
    }
};