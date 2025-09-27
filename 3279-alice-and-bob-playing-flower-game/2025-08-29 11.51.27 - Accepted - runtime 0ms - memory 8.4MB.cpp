class Solution {
public:
    long long flowerGame(int n, int m) {
        int oddcnt=(n+1)/2;
        int evencnt=m/2;
        long long ans=(long long)oddcnt*(long long)evencnt;

        evencnt=n/2;
        oddcnt=(m+1)/2;
        ans+=(long long)oddcnt*(long long)evencnt;
        return ans;


    }
};