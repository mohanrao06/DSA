class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        int tem=x;
        int sum=0;
       
       while(tem !=0){
        int rem=tem%10;
            sum=sum+rem;
        tem/=10;

       }
       if(x%sum==0){
        return sum;
       }else{
        return -1;
       }
        
    }
};