class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int ans=0;
        for(auto it:operations){
            string str=it;
            if(str=="--X" || str=="X--"){
                ans--;
            }else{
                ans++;
            }
        }
        return ans;
    }
};