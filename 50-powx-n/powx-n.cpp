class Solution {
public:
    double myPow(double x, int n) {
        long long temp=n;
        if(temp<0)temp=-1*temp;
        double ans=1.0;
        while(temp>0){
            if(temp%2!=0){
                ans=ans*x;
                temp-=1;

            }
            else{
                x*=x;
                temp=temp/2;
            }
        }
        if(n<0)ans=double(1.0)/ans;
        return ans;
    }
};