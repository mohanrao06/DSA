class Solution {
public:
    int maxProduct(int n) {
        int first=0,second=0;
        while(n>0){
            int num=n%10;
            if(num>first){
                second=first;
                first=num;
            }else if(num>second){
                second=num;
            }
            n/=10;

        }
        return first*second;
    }
};