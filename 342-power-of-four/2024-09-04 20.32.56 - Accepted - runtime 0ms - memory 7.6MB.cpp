class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0)return false;
        for(int i=0;i<=15;i++){
            int ans=pow(4,i);
            if(ans==n){
                return true;
                break;
            }
            if(ans>n)return false;

        }
        return false;
        
    }
};