class Solution {
public:
    int divide(int n, int m) {
        long ans=0;
        if(n==m)return 1;
        if (n == INT_MIN && m == -1) return INT_MAX;
        bool sign=true;
        if(n>=0 && m<0) sign=false;
        if(n<0 && m>=0) sign=false;
        long a=abs((long)n);
        long b=abs((long)m);
        while(a>=b){
            int cnt=0;
            while(a>=(b<<(cnt+1))){
                cnt++;
            }
            ans+=(1<<cnt);
            a=a-(b<<cnt);
        }
        
    return sign ? ans:(-1*ans);
    }
   
    
};