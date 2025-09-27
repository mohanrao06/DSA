class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        set<int>ans;
        set<int> curr;
        for(int i=0;i<arr.size();i++){
           set<int> curr2;
           curr.insert(arr[i]);
           for(auto x:curr){
                curr2.insert(x|arr[i]);
           }
           for(auto y:curr2){
            ans.insert(y);
           }
           curr=curr2;
        }
        return ans.size();
    }
};