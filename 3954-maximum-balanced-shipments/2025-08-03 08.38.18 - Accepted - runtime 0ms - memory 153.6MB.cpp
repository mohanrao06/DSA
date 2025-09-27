class Solution {
public:
    int maxBalancedShipments(vector<int>& weight) {
        int l=0;
        int r=0;
        int maxlen=0;
        int maxi=0;
        while(r<weight.size()){
            maxi=max(maxi,weight[r]);
            if(maxi>weight[r]){
                maxlen++;
                if(r<weight.size()-1){
                    l=r+1;
                    maxi=weight[l];
                }
            }
            r++;
        }
        return maxlen;
        
    }
};