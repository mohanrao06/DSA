class Solution {
public:
    bool isPrime(int n){
        if(n<=1){
            return false;
        }
         if (n == 2) return true;  
    if (n % 2 == 0) return false; 
        for(int i=3;i*i<=n;i+=2){
            if(n%i==0){
                return false;
            }
        }
        return true;
    }
    vector<int> closestPrimes(int left, int right) {
        vector<int> ans;
        for(int i=left;i<=right;i++){
            if(isPrime(i)){
                ans.push_back(i);
            }

        }
        if(ans.size()<2)return {-1,-1};
        int mindiff=INT_MAX;
        vector<int> res(2,-1);
        for(int i=1;i<ans.size();i++){
            if(ans[i]-ans[i-1]<mindiff){
                mindiff=ans[i]-ans[i-1];
                res={ans[i-1],ans[i]};
            }
        }
        return res;

        
    }
};