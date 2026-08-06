class Solution {
public:
    int smallestNumber(int n, int t) {
        int ans=0;
        for(int i=1;i<=10;i++){
            int pro=1;
            int num=n;
            while(num>0){
                int rem=num%10;
                pro*=rem;
                num=num/10;
            }
            if(pro%t==0){
                return n;
            }
            n++;
        }
        return t;

    }
};