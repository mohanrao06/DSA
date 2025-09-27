class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<=0){
            return false;
        }
        for(int i=0;i<=29;i++){
            long int ans=pow(3,i);
            if(ans==n){
                return true;
            }
        }
        return false;
    }
};