class Solution {
public:
    int reverse(int x) {
        int ans=0;
        int temp=x;
        while(temp!=0){
            int rem=temp%10;
            if(ans>INT_MAX/10 || ans<INT_MIN/10){
                return 0;
            }

            ans=(ans*10)+rem;
            temp=temp/10;
        }
        return ans;
    }
};