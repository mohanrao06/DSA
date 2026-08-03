class Solution {
public:
    int fun(int curr,int paste,int n){
        if(n==curr){
            return 0;
        }
        if(curr>n)return 10000;
        int opt1=2+fun(curr*2,curr,n);
        int opt2=1+fun(curr+paste,paste,n);
        return min(opt1,opt2);
    }
    int minSteps(int n) {
        if(n==1)return 0;
        return 1+ fun(1,1,n);
    }
};