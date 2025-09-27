class Solution {
public:
    int maximum69Number (int num) {
        int n=num;
        int pv=0;
        int curr=-1;
        while(n!=0){
            int rem=n%10;
            if(rem==6){
                curr=pv;
            }
            n=n/10;
            pv++;
        }
        return num+(3*pow(10,curr));
    }
};