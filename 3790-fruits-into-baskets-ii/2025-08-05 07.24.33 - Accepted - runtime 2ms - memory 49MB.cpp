class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int cnt=0;
        for(int i=0;i<fruits.size();i++){
            int flag=1;
            for(int j=0;j<baskets.size();j++){
                if(fruits[i]<=baskets[j]){
                    baskets[j]=0;
                    flag=0;
                    break;
                }
            }
            cnt+=flag;
        }
        return cnt;
    }
};