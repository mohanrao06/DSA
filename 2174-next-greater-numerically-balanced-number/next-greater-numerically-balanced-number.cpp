class Solution {
public:
    bool isBalanced(int x){
        int cnt[10]={0};
        while(x>0){
            int rem=x%10;
            cnt[rem]++;
            x=x/10;
        }
        for(int i=0;i<10;i++){
            if(cnt[i]>0 && i!=cnt[i]){
                return false;
            }
        }
        return true;
    }
    int nextBeautifulNumber(int n) {
        for(int i=n+1;i<INT_MAX;i++){
            if(isBalanced(i))return i;
        }
        return -1;
    }
};