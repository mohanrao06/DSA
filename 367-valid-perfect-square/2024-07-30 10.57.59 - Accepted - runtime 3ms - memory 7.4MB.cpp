class Solution {
public:
    bool isPerfectSquare(int num) {
        int start=1;
        int end=num;
        if(num==1){
            return true;
        }
        
        while(start<end){
            long long int mid=start+(end-start)/2;
            if(mid*mid == num){
                return true;
            }else if(mid*mid > num){
                end=mid;
            }else{
                start=mid+1;
            }
        }
        return false;
        
    }
};