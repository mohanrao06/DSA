class Solution {
public:
    int M=1e9+7;
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        
        vector<int> powers;
        for(int i=0;i<32;i++){
            if((n&(1<<i))!=0){
                powers.push_back((1<<i));

            }
        }
        vector<int> res;
        for(auto &q:queries){
            int left=q[0];
            int right=q[1];
            long product=1;
            for(int j=left;j<=right;j++){
                product=(product*powers[j])%M;
            }
            res.push_back(int(product));
        }
        return res;
    }
};