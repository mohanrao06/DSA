class Solution {
public:
    void combination(vector<vector<int>>& result, vector<int> temp, int k, int n){
        if(temp.size()==k && n==0){
            result.push_back(temp);
            return;
        }
        if(temp.size()<k){
            for(int i= temp.empty()?1:temp.back()+1;i<=9;i++){
                if(n-i<0)break;
                temp.push_back(i);
                combination(result,temp,k,n-i);
                temp.pop_back();

            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> temp;
        combination(result, temp, k, n);
        return result;
    }
};