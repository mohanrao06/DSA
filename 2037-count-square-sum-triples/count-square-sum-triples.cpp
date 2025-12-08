class Solution {
public:
    int countTriples(int n) {
        unordered_set<long long> mp;
        for(int i=1;i<=n;i++){
            mp.insert(i*i);
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                int sq=(i*i)+(j*j);
                if(mp.count(sq)){
                    ans++;
                }
            }
        }
        return ans;
    }
};